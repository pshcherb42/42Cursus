#!/bin/bash

WP_PATH="/var/www/html/wordpress"

# Wait for MariaDB to be ready
echo "Waiting for MariaDB..."
until mysqladmin ping -h"${MYSQL_HOST}" -u"${MYSQL_USER}" -p"${MYSQL_PASSWORD}" --silent 2>/dev/null; do
    sleep 2
done
echo "MariaDB is up."

cd "$WP_PATH"

# Download WordPress core if not present
if [ ! -f "$WP_PATH/wp-config.php" ]; then
    echo "Setting up WordPress..."

    # Download WordPress
    wp core download --allow-root --locale=en_US

    # Create wp-config.php
    wp config create \
        --allow-root \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${MYSQL_PASSWORD}" \
        --dbhost="${MYSQL_HOST}" \
        --dbprefix=wp_

    # Install WordPress
    wp core install \
        --allow-root \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email

    # Create an additional (non-admin) WordPress user
    wp user create \
        --allow-root \
        "${WP_USER}" "${WP_USER_EMAIL}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role=author

    # Install and configure Redis Object Cache plugin
    wp plugin install redis-cache --activate --allow-root

    # Point WordPress to the Redis container
    wp config set WP_REDIS_HOST redis --allow-root
    wp config set WP_REDIS_PORT 6379 --allow-root

    # Enable the Redis object cache
    wp redis enable --allow-root

    echo "WordPress installation complete."
else
    echo "WordPress already configured."
fi

# Start php-fpm in foreground
echo "Starting php-fpm..."
exec php-fpm$(php -r "echo PHP_MAJOR_VERSION.'.'.PHP_MINOR_VERSION;") -F
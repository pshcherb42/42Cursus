#!/bin/bash

# Start MariaDB service temporarily for initialization
service mariadb start

# Wait until MariaDB is ready
until mysqladmin ping --silent; do
    echo "Waiting for MariaDB to be ready..."
    sleep 1
done

# Create database and user from environment variables
mysql -u root <<EOF
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

# Stop the temporary service and restart mysqld in foreground
service mariadb stop

# Run MariaDB in foreground, binding to all interfaces
exec mysqld --bind-address=0.0.0.0
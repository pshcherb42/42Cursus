FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    php \
    php-fpm \
    php-mysql \
    php-curl \
    php-gd \
    php-mbstring \
    php-xml \
    php-xmlrpc \
    php-soap \
    php-intl \
    php-zip \
    wget \
    curl \
    default-mysql-client \
    && rm -rf /var/lib/apt/lists/*

# Install WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Configure php-fpm to listen on TCP instead of unix socket
RUN PHP_VERSION=$(php -r "echo PHP_MAJOR_VERSION.'.'.PHP_MINOR_VERSION;") && \
    sed -i "s|listen = /run/php/php${PHP_VERSION}-fpm.sock|listen = 0.0.0.0:9000|" \
    /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf && \
    mkdir -p /var/www/html/wordpress /run/php

COPY conf/wp-setup.sh /usr/local/bin/wp-setup.sh
RUN chmod +x /usr/local/bin/wp-setup.sh

EXPOSE 9000

CMD ["/usr/local/bin/wp-setup.sh"]
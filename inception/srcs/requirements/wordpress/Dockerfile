FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    php7.4 \
    php7.4-fpm \
    php7.4-mysql \
    php7.4-curl \
    php7.4-gd \
    php7.4-mbstring \
    php7.4-xml \
    php7.4-xmlrpc \
    php7.4-soap \
    php7.4-intl \
    php7.4-zip \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Install WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Configure php-fpm to listen on all interfaces (TCP socket)
RUN sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 0.0.0.0:9000|' \
    /etc/php/7.4/fpm/pool.d/www.conf && \
    sed -i 's|;listen.owner = www-data|listen.owner = www-data|' \
    /etc/php/7.4/fpm/pool.d/www.conf && \
    sed -i 's|;listen.group = www-data|listen.group = www-data|' \
    /etc/php/7.4/fpm/pool.d/www.conf

RUN mkdir -p /var/www/html/wordpress && \
    mkdir -p /run/php

COPY conf/wp-setup.sh /usr/local/bin/wp-setup.sh
RUN chmod +x /usr/local/bin/wp-setup.sh

EXPOSE 9000

CMD ["/usr/local/bin/wp-setup.sh"]
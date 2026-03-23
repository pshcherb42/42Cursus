FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    php \
    php-mysqli \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Download Adminer (single PHP file database manager)
RUN mkdir -p /var/www/adminer && \
    wget -O /var/www/adminer/index.php \
    https://www.adminer.org/latest.php

EXPOSE 8080

# Run Adminer using PHP's built-in web server
CMD ["php", "-S", "0.0.0.0:8080", "-t", "/var/www/adminer"]
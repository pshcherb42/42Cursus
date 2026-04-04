#!/bin/bash

# Start MariaDB temporarily for initialization
mysqld --user=mysql --bootstrap << SQLEOF
USE mysql;
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
SQLEOF

echo "Database initialized. Starting mysqld..."

# Run MariaDB in foreground, accessible from other containers
exec mysqld --user=mysql --bind-address=0.0.0.0
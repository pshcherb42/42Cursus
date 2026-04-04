FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

# Create the directory for the socket file
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

COPY conf/create_db.sh /docker-entrypoint-initdb.d/create_db.sh
RUN chmod +x /docker-entrypoint-initdb.d/create_db.sh

EXPOSE 3306

CMD ["bash", "/docker-entrypoint-initdb.d/create_db.sh"]
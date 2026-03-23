FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

COPY conf/create_db.sh /docker-entrypoint-initdb.d/create_db.sh
RUN chmod +x /docker-entrypoint-initdb.d/create_db.sh

EXPOSE 3306

CMD ["bash", "/docker-entrypoint-initdb.d/create_db.sh"]
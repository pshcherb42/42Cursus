FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    redis-server \
    && rm -rf /var/lib/apt/lists/*

# Configure Redis:
# - Listen on all interfaces (not just localhost)
# - Set max memory and eviction policy suitable for WordPress cache
RUN sed -i "s/bind 127.0.0.1 -::1/bind 0.0.0.0/" /etc/redis/redis.conf && \
    sed -i "s/# maxmemory <bytes>/maxmemory 256mb/" /etc/redis/redis.conf && \
    sed -i "s/# maxmemory-policy noeviction/maxmemory-policy allkeys-lru/" /etc/redis/redis.conf

EXPOSE 6379

CMD ["redis-server", "/etc/redis/redis.conf"]
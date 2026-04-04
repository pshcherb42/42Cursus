FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    wget \
    ca-certificates \
    tar \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /data /portainer-public && \
    wget -q --tries=5 --timeout=120 --retry-connrefused \
    -O /tmp/portainer.tar.gz \

https://github.com/portainer/portainer/releases/download/2.20.3/portainer-2.20.3-linux-arm64.tar.gz && \
    tar -xzf /tmp/portainer.tar.gz -C /tmp && \
    mv /tmp/portainer/portainer /usr/local/bin/portainer && \
    mv /tmp/portainer/public /portainer-public && \
    rm -rf /tmp/portainer*

EXPOSE 9000

CMD ["/usr/local/bin/portainer", "--data", "/data", "--assets", "/portainer-public"]


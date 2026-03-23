FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    wget \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Download the Portainer CE binary directly (no image pull)
RUN wget -O /usr/local/bin/portainer \
    https://github.com/portainer/portainer/releases/download/2.20.3/portainer-2.20.3-linux-amd64.tar.gz && \
    cd /tmp && \
    wget -q https://github.com/portainer/portainer/releases/download/2.20.3/portainer-2.20.3-linux-amd64.tar.gz \
        -O portainer.tar.gz && \
    tar -xzf portainer.tar.gz && \
    mv portainer/portainer /usr/local/bin/portainer && \
    mv portainer/public /portainer-public && \
    rm -rf /tmp/portainer*

RUN mkdir -p /data

EXPOSE 9000

CMD ["/usr/local/bin/portainer", "--data", "/data", "--assets", "/portainer-public"]
*This project has been created as part of the 42 curriculum by pshcherb.*

---

## Description

Inception is a system administration project from the 42 school curriculum. The goal is to set up a small but complete web infrastructure using **Docker** and **Docker Compose**, entirely inside a virtual machine.

The infrastructure consists of three services running in dedicated containers:

- **NGINX** — the sole entry point, serving HTTPS traffic on port 443 using TLSv1.2 or TLSv1.3 only
- **WordPress + php-fpm** — the web application layer, running without NGINX
- **MariaDB** — the relational database storing all WordPress data

All images are built from scratch using custom Dockerfiles based on Debian Bookworm (penultimate stable release). No pre-built images are pulled from DockerHub or any registry (except the base Debian image).

### Project Description

#### Use of Docker

Docker is used to isolate each service into its own container, giving each one a clean, reproducible environment. Docker Compose orchestrates the three containers, their shared network, and their persistent volumes. Each `Dockerfile` is written manually and called through the `docker-compose.yml`, which is itself invoked by the `Makefile`.

The source files included in the project are:

- `Makefile` — entry point that builds and runs the entire infrastructure
- `srcs/docker-compose.yml` — defines services, volumes, and the network
- `srcs/.env` — environment variables (credentials, configuration)
- `srcs/requirements/nginx/` — Dockerfile and NGINX configuration
- `srcs/requirements/wordpress/` — Dockerfile and WordPress setup script
- `srcs/requirements/mariadb/` — Dockerfile and MariaDB initialization script

#### Main Design Choices

- NGINX is the **only exposed service** (port 443). WordPress and MariaDB are only reachable internally through the Docker network.
- **WP-CLI** is used inside the WordPress container to automate installation — no manual setup required.
- A **startup loop** in the WordPress script waits for MariaDB to be truly ready before attempting to connect, compensating for the limitation of `depends_on`.
- Named volumes use `driver: local` with `driver_opts` to store data at a specific host path (`/home/login/data/`) as required by the project rules.

---

#### Virtual Machines vs Docker

| | Virtual Machine | Docker Container |
|--|----------------|-----------------|
| Isolation | Full OS-level isolation | Process-level isolation |
| Size | GBs (includes full OS) | MBs (shares host kernel) |
| Startup time | Minutes | Seconds |
| Use case | Run different OS, full environments | Run isolated applications |
| Overhead | High (hypervisor + full OS) | Low (shares host kernel) |

A VM virtualizes the entire hardware stack and runs a full operating system. Docker containers share the host kernel and only package the application and its dependencies, making them much lighter and faster to start.

#### Secrets vs Environment Variables

| | Environment Variables | Secrets |
|--|----------------------|---------|
| Storage | Plain text in `.env` file | Encrypted at rest |
| Access | Any process in the container | Only mounted to specific services |
| Use case | Development, school projects | Production systems |
| Tools | Docker `.env`, `env_file` | Docker Swarm secrets, Vault, AWS Secrets Manager |

Environment variables (used in this project via `.env`) are simple and practical for development but store credentials in plain text. In production, secrets managers encrypt sensitive values and expose them only to authorized services, reducing the risk of credential leaks.

#### Docker Network vs Host Network

| | Docker Network (bridge) | Host Network |
|--|------------------------|-------------|
| Isolation | Containers have their own network namespace | Containers share the host network stack |
| Port mapping | Explicit (`ports:` field) | No mapping needed, uses host ports directly |
| Security | Better — containers are isolated | Weaker — full access to host network |
| Use case | Most containerized applications | High-performance scenarios needing raw network access |

This project uses a **bridge network** (`inception`) so containers can communicate with each other by service name while remaining isolated from the outside world. Only NGINX exposes a port to the host (`443:443`).

#### Docker Volumes vs Bind Mounts

| | Named Volumes | Bind Mounts |
|--|--------------|-------------|
| Managed by | Docker | You (host filesystem) |
| Syntax | `volume_name:/path` | `./host/path:/container/path` |
| Portability | High — works on any machine | Low — depends on host directory structure |
| Performance | Better | Slightly lower |
| Allowed in this project | ✅ Yes | ❌ No |

This project uses **named volumes** with `driver_opts` to store data at `/home/login/data/` on the host. This satisfies both the requirement of using named volumes and the requirement of storing data at a specific host path.

---

## Instructions

### Prerequisites

- A Linux virtual machine (Debian or Ubuntu recommended)
- Docker Engine installed
- Docker Compose v2 installed
- `make` installed

### Setup

**1. Clone the repository**

```bash
git clone https://github.com/<login>/inception.git
cd inception
```

**2. Configure your credentials**

Copy the example env file and fill in your values:

```bash
cp srcs/.env.example srcs/.env
nano srcs/.env
```

**3. Replace `login` with your 42 username**

In the `Makefile`:
```makefile
LOGIN = your_login
```

In `srcs/requirements/nginx/Dockerfile`, update the certificate subject:
```
-subj "/C=ES/.../CN=your_login.42.fr"
```

In `srcs/.env`:
```
WP_URL=https://your_login.42.fr
```

**4. Add your domain to `/etc/hosts`**

```bash
echo "127.0.0.1 your_login.42.fr" | sudo tee -a /etc/hosts
```

### Running the project

```bash
# Build images and start all containers
make

# Stop all containers
make down

# View logs
make logs

# Full cleanup (removes containers, images, and data)
make fclean

# Rebuild from scratch
make re
```

### Accessing the services

| Service | URL |
|---------|-----|
| WordPress site | `https://your_login.42.fr` |
| WordPress admin | `https://your_login.42.fr/wp-admin` |

> Note: Your browser will show a security warning because the TLS certificate is self-signed. This is expected — proceed to the site manually.

---

## Resources

### Documentation

- [Docker official documentation](https://docs.docker.com/)
- [Docker Compose file reference](https://docs.docker.com/compose/compose-file/)
- [NGINX documentation](https://nginx.org/en/docs/)
- [MariaDB Knowledge Base](https://mariadb.com/kb/en/)
- [WordPress Developer Documentation](https://developer.wordpress.org/)
- [WP-CLI documentation](https://wp-cli.org/)
- [PHP-FPM documentation](https://www.php.net/manual/en/install.fpm.php)
- [Debian releases](https://www.debian.org/releases/)

### Articles & Tutorials

- [Docker networking overview](https://docs.docker.com/network/)
- [Docker volumes documentation](https://docs.docker.com/storage/volumes/)
- [Understanding Docker bind mounts vs volumes](https://docs.docker.com/storage/)
- [TLS protocol versions explained](https://www.cloudflare.com/learning/ssl/what-is-tls/)
- [FastCGI and php-fpm with NGINX](https://www.nginx.com/resources/wiki/start/topics/examples/phpfcgi/)

### AI Usage

**Claude (Anthropic)** was used during this project for the following tasks:

- **Project scaffolding** — generating the initial structure of Dockerfiles, `docker-compose.yml`, and the Makefile based on the project requirements
- **Configuration files** — writing the NGINX configuration (`nginx.conf`) with correct TLS settings and FastCGI proxy rules
- **Shell scripting** — writing the MariaDB initialization script (`create_db.sh`) and the WordPress automated setup script (`wp-setup.sh`)
- **Explanations and understanding** — clarifying concepts such as named volumes vs bind mounts, Docker networking, `depends_on` limitations, and TLS configuration
- **Debugging guidance** — explaining why certain configurations (startup wait loops, `restart` policies, shared volumes) are necessary

All generated code was reviewed, understood, and adapted to meet the specific requirements of the project. AI was used as a learning and productivity tool, not as a replacement for understanding the concepts involved.
https://docs.docker.com/engine/storage/bind-mounts/

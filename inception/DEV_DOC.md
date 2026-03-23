# Developer Documentation — Inception

## Setting up the environment from scratch

### Prerequisites

Make sure the following are installed on your virtual machine:

| Tool | Check | Install (Debian/Ubuntu) |
|------|-------|------------------------|
| Docker Engine | `docker --version` | [docs.docker.com/engine/install](https://docs.docker.com/engine/install/) |
| Docker Compose v2 | `docker compose version` | Included with Docker Engine |
| make | `make --version` | `sudo apt install make` |
| git | `git --version` | `sudo apt install git` |

> Docker Compose v2 is required. The project uses `docker compose` (with a space), not the legacy `docker-compose` command.

### Clone the repository

```bash
git clone https://github.com/<login>/inception.git
cd inception
```

### Configuration files

**1. Create the `.env` file**

The `.env` file holds all credentials and configuration values. A template is provided:

```bash
cp srcs/.env.example srcs/.env
```

Edit it and replace all placeholder values with your own:

```bash
nano srcs/.env
```

Contents:

```env
# MariaDB
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_PASSWORD=your_secure_password
MYSQL_ROOT_PASSWORD=your_secure_root_password
MYSQL_HOST=mariadb

# WordPress
WP_URL=https://login.42.fr
WP_TITLE=Inception
WP_ADMIN_USER=wpadmin
WP_ADMIN_PASSWORD=your_admin_password
WP_ADMIN_EMAIL=admin@login.42.fr

# Second WordPress user (non-admin)
WP_USER=wpeditor
WP_USER_EMAIL=editor@login.42.fr
WP_USER_PASSWORD=your_editor_password
```

**2. Set your login in the Makefile**

Open the `Makefile` and update the `LOGIN` variable:

```makefile
LOGIN = your_42_login
```

This controls where data is stored on the host: `/home/your_42_login/data/`.

**3. Update NGINX certificate and WordPress URL**

In `srcs/requirements/nginx/Dockerfile`, update the certificate subject:
```dockerfile
-subj "/C=ES/ST=Catalonia/L=Barcelona/O=42/CN=your_login.42.fr"
```

**4. Add the domain to `/etc/hosts`**

```bash
echo "127.0.0.1 your_login.42.fr" | sudo tee -a /etc/hosts
```

---

## Building and launching the project

The entire build and launch process is managed through the `Makefile`.

### Project structure

```
inception/
├── Makefile                          ← entry point
└── srcs/
    ├── docker-compose.yml            ← orchestration
    ├── .env                          ← credentials (never commit)
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   └── conf/nginx.conf
        ├── wordpress/
        │   ├── Dockerfile
        │   └── conf/wp-setup.sh
        └── mariadb/
            ├── Dockerfile
            └── conf/create_db.sh
```

### Build chain

```
make
  └─► docker compose -f srcs/docker-compose.yml build
        ├─► builds nginx     from requirements/nginx/Dockerfile
        ├─► builds wordpress from requirements/wordpress/Dockerfile
        └─► builds mariadb   from requirements/mariadb/Dockerfile
```

### Available make targets

| Command | What it does |
|---------|-------------|
| `make` | Creates data directories, builds images, starts containers |
| `make build` | Builds all Docker images only |
| `make up` | Starts containers (images must already be built) |
| `make down` | Stops and removes containers (data preserved) |
| `make clean` | Stops containers and removes images |
| `make fclean` | Full cleanup — removes containers, images, and host data |
| `make re` | `fclean` + `all` — full rebuild from scratch |
| `make logs` | Tail logs from all containers |
| `make ps` | Show status of all containers |

---

## Managing containers and volumes

### Useful Docker commands

**List running containers:**
```bash
docker ps
```

**Enter a running container:**
```bash
docker exec -it nginx bash
docker exec -it wordpress bash
docker exec -it mariadb bash
```

**Restart a single container:**
```bash
docker restart wordpress
```

**View logs for one container:**
```bash
docker logs -f mariadb
```

**Inspect the Docker network:**
```bash
docker network inspect srcs_inception
```

**List all volumes:**
```bash
docker volume ls
```

**Inspect a volume:**
```bash
docker volume inspect srcs_wordpress_data
docker volume inspect srcs_mariadb_data
```

### Connect to the database directly

```bash
docker exec -it mariadb mysql -u root -p
# enter MYSQL_ROOT_PASSWORD from .env
```

Or connect as the WordPress user:
```bash
docker exec -it mariadb mysql -u wpuser -p wordpress
# enter MYSQL_PASSWORD from .env
```

---

## Data storage and persistence

### Where data lives on the host

All persistent data is stored on the host machine at:

```
/home/<login>/data/
├── wordpress/    ← WordPress core files, themes, plugins, uploads
└── mariadb/      ← MariaDB database files
```

These directories are created automatically when you run `make`.

### How persistence works

The project uses **Docker named volumes** configured to bind to the host paths above:

```yaml
volumes:
  wordpress_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/wordpress

  mariadb_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/mariadb
```

Both the `nginx` and `wordpress` containers mount `wordpress_data` at `/var/www/html/wordpress` — NGINX needs to read the PHP files to serve them, and WordPress needs to write them during installation and use.

The `mariadb` container exclusively mounts `mariadb_data` at `/var/lib/mysql` — the standard path where MariaDB stores its internal database files.

### What happens to data on container operations

| Operation | WordPress files | Database |
|-----------|----------------|----------|
| `make down` | ✅ Preserved | ✅ Preserved |
| `make clean` | ✅ Preserved | ✅ Preserved |
| `docker restart wordpress` | ✅ Preserved | ✅ Preserved |
| Container crashes and restarts | ✅ Preserved | ✅ Preserved |
| `make fclean` | ❌ Deleted | ❌ Deleted |

Since data lives on the host filesystem (not inside the container layer), it survives container restarts, rebuilds, and even VM reboots — as long as `make fclean` is not run.

### WordPress installation behavior

The `wp-setup.sh` script checks whether `wp-config.php` already exists before running the installer:

```bash
if [ ! -f "$WP_PATH/wp-config.php" ]; then
    # first run — install WordPress
else
    # already installed — skip
fi
```

This means on the **first `make`**, WordPress is downloaded and installed automatically. On all subsequent starts, it skips installation and goes straight to starting php-fpm.
# User Documentation — Inception

## What services does this stack provide?

This project runs a complete WordPress website accessible via HTTPS. It is made up of three services working together:

| Service | Role | Accessible from outside? |
|---------|------|--------------------------|
| **NGINX** | Web server — handles all incoming traffic securely over HTTPS | ✅ Yes — port 443 only |
| **WordPress** | The website and admin panel — powered by php-fpm | ❌ No — internal only |
| **MariaDB** | The database — stores all website content and users | ❌ No — internal only |

As a user or administrator, you only ever interact with NGINX directly. WordPress and MariaDB are internal services — they are not reachable from outside the infrastructure.

---

## Starting and stopping the project

Open a terminal inside the virtual machine and navigate to the project root (where the `Makefile` is located).

**Start the project:**
```bash
make
```
This builds all Docker images and starts all three containers. The first run may take a few minutes while WordPress is being installed automatically.

**Stop the project (containers only):**
```bash
make down
```
This stops and removes the containers. Your data (database, WordPress files) is preserved on disk.

**Stop and remove everything including data:**
```bash
make fclean
```
> ⚠️ Warning: this deletes all WordPress content and database data permanently.

**Restart from scratch:**
```bash
make re
```

---

## Accessing the website

Once the project is running, open a browser on the virtual machine and go to:

| Page | URL |
|------|-----|
| WordPress website | `https://login.42.fr` |
| WordPress admin panel | `https://login.42.fr/wp-admin` |

> Replace `login` with the actual username of the project owner.

### Browser security warning

Your browser will display a warning saying the connection is not trusted. This is expected — the project uses a **self-signed TLS certificate**. To proceed:

- **Chrome / Chromium** — click "Advanced" then "Proceed to login.42.fr"
- **Firefox** — click "Advanced" then "Accept the Risk and Continue"

This warning does not affect functionality. It simply means the certificate was not issued by a public authority.

---

## Credentials

All credentials are stored in a single file:

```
srcs/.env
```

This file is located inside the project folder. Open it with any text editor:

```bash
nano srcs/.env
```

It contains the following credentials:

| Variable | What it is |
|----------|-----------|
| `MYSQL_ROOT_PASSWORD` | MariaDB root password |
| `MYSQL_USER` / `MYSQL_PASSWORD` | MariaDB user used by WordPress |
| `WP_ADMIN_USER` / `WP_ADMIN_PASSWORD` | WordPress administrator login |
| `WP_USER` / `WP_USER_PASSWORD` | Secondary WordPress user (author role) |

> ⚠️ Never share or commit this file. It contains sensitive credentials.

---

## Checking that the services are running correctly

**Check container status:**
```bash
make ps
```

All three containers should show as `Up`:
```
NAME        STATUS
nginx       Up
wordpress   Up
mariadb     Up
```

**Check live logs for all services:**
```bash
make logs
```

**Check logs for a specific service:**
```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

**Quick connectivity test:**

Open `https://login.42.fr` in your browser. If the WordPress homepage loads, the full stack is working correctly — NGINX is serving traffic, WordPress is processing PHP, and MariaDB is responding to database queries.
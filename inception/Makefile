LOGIN		= pshcherb
DATA_DIR	= /home/$(LOGIN)/data
COMPOSE		= docker compose -f srcs/docker-compose.yml
 
.PHONY: all build up down clean fclean re
 
all: build up
 
build: create_dirs
	$(COMPOSE) build
 
up:
	$(COMPOSE) up -d
 
down:
	$(COMPOSE) down
 
# Stop and remove containers, images, and orphaned containers
clean: down
	$(COMPOSE) down --rmi all --volumes --remove-orphans || true
 
# Full cleanup including host data directories
fclean: clean
	sudo rm -rf $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb $(DATA_DIR)/portainer
	docker system prune -af --volumes || true
 
re: fclean all
 
create_dirs:
	@mkdir -p $(DATA_DIR)/wordpress
	@mkdir -p $(DATA_DIR)/mariadb
	@mkdir -p $(DATA_DIR)/portainer
 
logs:
	$(COMPOSE) logs -f
 
ps:
	$(COMPOSE) ps


*This project was created as a part of 42 cursus by pshcherb*

# Description

Actualiza tus repositorios e instala los paquetes necesarios para manejar repositorios vía HTTPS:
apt install ca-certificates curl gnupg

Configurar el repositorio oficial de Docker
Crear directorio para llaves
install -m 0755 -d /etc/apt/keyrings

Descargar la llave GPG oficial
curl -fsSL https://download.docker.com/linux/debian/gpg | gpg --dearmor -o /etc/apt/keyrings/docker.gpg
chmod a+r /etc/apt/keyrings/docker.gpg

Añadir el repositorio a tus fuentes de APT
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  tee /etc/apt/sources.list.d/docker.list > /dev/null

  Instalar docker engine

  apt update
apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

Cómo funciona Docker Compose

Para crear un Docker Compose necesitamos crear un fichero docker-compose.yml. Este fichero es donde indicaremos qué servicios queremos que se ejecuten y de qué manera.

En este sentido, comentar que Docker Compose cuenta con varios apartados:

Definición de la versión (Opcional, deprecado)
Servicios (Requerido)
Redes
Volúmenes
Configs
Secrets

Create A Docker Image And Run It As Container
Follow the below steps to create a Docker Image and run a Container:

Step 1: Create a Dockerfile.

Step 2: Run the following command in the terminal and it will create a docker image of the application and download all the necessary dependencies needed for the application to run successfully.

docker build -t <name>:<tag> 
This will start building the image.

Step 3:  We have successfully created a Dockerfile and a respective Docker image for the same.

Step 4: Run the following command in the terminal and it will create a running container with all the needed dependencies and start the application.

docker run -p 9000:80 <image-name>:<tag> 
The 9000 is the port we want to access our application on. 80 is the port the container is exposing for the host to access.

# Instructions

# Resources

Docker Container Fundamentals
https://www.nxp.com/docs/en/supporting-information/DOCKER-CONTAINER-FUNDAMENTALS.pdf

What is and why use Docker Compose
https://anderfernandez.com/blog/tutorial-docker-compose/

What is Docker image?
https://www.geeksforgeeks.org/devops/what-is-docker-image/

Nginx
https://es.wikipedia.org/wiki/Nginx

nginx-dockerfile
https://www.datacamp.com/es/tutorial/nginx-docker
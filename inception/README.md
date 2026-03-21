*This project was created as a part of 42 cursus by pshcherb*

# Description

Empezamos por la esructura del proyecto. Se dice en el subject que la carpeta tiene que tener dentro otra carpeta que se llame srcs - "All the files required for the configuration of your project must be placed in a srcs
folder." y que Makefile tiene que estar en el root. 

Dentro de srcs creamos docker_compose.yml (acosnsejo escribir docker_compose.yml a mano, nada de copiar y pegar, porque Docker es muy sensible con el tema de espacios y tabulacion), este va a ser como el main que va utilizar el docker para crear contendores. Arriba del todo antes se escribia la version de docker compose que en este caso no lo vamos a hacer porque es una practica anticuada, Docker actual ignora este campo igualmente.

Escribimos services: y los servicios que no pide el subject, deberia quedar asi(cada campo subyacente tiene 2 espacios de separacion):

<img width="400" height="257" alt="Image" src="https://github.com/user-attachments/assets/ca7db17a-2b40-4718-a93a-a2b1c33f13ef" />

Y para seguir vamos a ajustar nuestra estructura de carpetas. Dentro de srcs creamo scarpeta services(o cualquier otro nombre, eso no importa) y dentro de services creamos tres carpetas cada una con nombre dep servicio correspondiente(o cualquier otro nombre). Y dentro de cada carpeta creamos Dokerfile(asi sin extencion, ese si tiene que tener ese nombre). Quedaria asi la estrucutra del proyecto:



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

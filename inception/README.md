*This project was created as a part of 42 cursus by pshcherb*

# Description

Empezamos por la esructura del proyecto. Se dice en el subject que la carpeta tiene que tener dentro otra carpeta que se llame srcs - "All the files required for the configuration of your project must be placed in a srcs
folder." y que Makefile tiene que estar en el root. 

Dentro de srcs creamos docker_compose.yml (acosnsejo escribir docker_compose.yml a mano, nada de copiar y pegar, porque Docker es muy sensible con el tema de espacios y tabulacion), este va a ser como el main que va utilizar el docker para crear contendores. Arriba del todo antes se escribia la version de docker compose que en este caso no lo vamos a hacer porque es una practica anticuada, Docker actual ignora este campo igualmente.

Escribimos services: y los servicios que no pide el subject, deberia quedar asi(cada campo subyacente tiene 2 espacios de separacion):

<img width="400" height="257" alt="Image" src="https://github.com/user-attachments/assets/ca7db17a-2b40-4718-a93a-a2b1c33f13ef" />

Y para seguir vamos a ajustar nuestra estructura de carpetas. Dentro de srcs creamo scarpeta services(o cualquier otro nombre, eso no importa) y dentro de services creamos tres carpetas cada una con nombre dep servicio correspondiente(o cualquier otro nombre). Y dentro de cada carpeta creamos Dokerfile(asi sin extencion, ese si tiene que tener ese nombre). Quedaria asi la estrucutra del proyecto:

<img width="286" height="476" alt="Image" src="https://github.com/user-attachments/assets/785abb34-005a-41b3-a3cf-36c32bd4ccf0" />

Ahora podemos seguir con el siguente campo de build: aqui escribimos la ruta del Dockerfile, y tambien rellenamos el campo de image: con el nombre del servicio, normalmente si tenemos campo build: no necesitariamos el campo image:, pero lo añadimos porque el subject nos pide "Each Docker image must have the same name as its corresponding service."Va a quedar asi:

<img width="354" height="299" alt="Image" src="https://github.com/user-attachments/assets/c483ecd1-03f7-459d-8357-dbc624725bb5" />

Y lo mismo para el campo de container_name:, docker ps nos muestra los contenedores que estan funcionando y les crea nombres automaticamente tipo srcs-mariadb-1, con container_name: le decimos a docker llama a este seervicio de tal manera, pero para networking features no tiene ninguna importancia, como si lo llamaramos unicornio.

Seguimos con la opcion restart:, el subject nos dice "Your containers have to restart in case of a crash.", hay tres opciones que nos podrian servir - always, unless-stopped y on-failure. Vamos a elegir unless-stopped porque always reinicia incluso si paramos manualmente y on-failure tambien reincia incluso si lo paramos manualmente y ademas no reinicia si el codigo de error es 0, asi que unless-stopped es la mejor version porque reincia siempre excepto si lo paramos manualmente.



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

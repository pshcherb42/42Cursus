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

<img width="388" height="412" alt="Image" src="https://github.com/user-attachments/assets/a6a8dea3-f319-43b4-bce1-68c028a0cfe3" />

ports: permite indicar que puertos se van a exponer al host. El subject dice que "Your NGINX container must be the only entrypoint into your
infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3
protocol." Con los protocolos de seguridad nos ocupamos despues en nginx.conf. 

Ahora con las dependencias. Tenemos que preguntarnos que necesita cada servicio para arrancar? Nginx necesita algo?-si, necesita php de wordpress para enviar requests. Vale, y wordpress, necesita algo para arrancar? - si, una base de datos, para guardar/leer datos. Llegamos a mariaDB , necesita algo para arrancar? - no. Ya sabes el orden de dependencias. Es una cuestion de arquitectura y logica.

<img width="457" height="480" alt="Image" src="https://github.com/user-attachments/assets/354d414d-e0d4-4a57-9c70-4c23f1b0f742" />

env_file: permite añadir variables de entorno al contenedor basado en uno a varios ficheros .env, tambien podemos definir las variables manualmente con environment: pero es mala practica porque asi estariamos dejando las llaves de casa en la puerta en vez de guardarlas en un sitio seguro. Solo nginx NO necesita env_file porque no tiene acceso a ninguna informacion sensible, solo manda php requests y escucha en el puerto. 

Con volumes: todo es un poco mas complicado. Como concepto es simple, son archivos de nuestro local que seran copiados al contenedor. Los necesitamos para que cuando apaguemos el contendor no perder los datos. Docker compose crea volumenes automaticamente pero despues de docker rm los elimina, con volumes: seguimos teniendo los datos para backup o backend. A veces las rutas son predefenidas como en el caso de la base de datos, y otras veces podemos crear nuestars propias rutas como en caso de pagina web y servidor, pero vamos a usar la ruta predefenida en ambos casos solo por la comodidad. Primer parametro de volumes es el nombre del volumen, mariadb_data para la base de datos y wordpress_data para la web. Nginx y wordpress comparten el mismo volumen, porque nginx necesita leer archivos php de wordpress, mariadb no comunica con nadie, solo necesita persistir sus propios archivos. Bind mount are options for volume which we are not authorized to use. We can safe volumes on cloud, on our machine, on network server... etc. In the subject specified the route we need to use to safe volumes and is /home/login/data, so for driver: we use local.

Dentro de Driver_opts: especificamos la ruta /home/login/data. Type: cual sistema de ficheros usar para montar? puede ser none- usa el sitema de ficheros existente, nfs- network file system, tmpfs- temporary, ext4 - linux filesystem(para cada sistema operativo seria diferente). O: opciones extra, bind significa copiar los datos al fichero existente(/home/login/data/wordpress  ←→  /var/www/html/wordpress), un aes ruta en el host y la otra en contenedor, el contenedor no sabe que existe home,dentro del contenedor esta ruta no existe, por eso necesitamos dos rutas separadas con la misma informacion. El volumen sirve como traductor entre dos idiomas diferentes. 

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

WordPress
https://es.wikipedia.org/wiki/WordPress

MariaDB en Docker: guía de in­s­ta­la­ción paso a paso
https://www.ionos.com/es-us/digitalguide/hosting/cuestiones-tecnicas/mariadb-en-docker/

Levantar un WordPress con Compose
https://aulasoftwarelibre.github.io/taller-de-docker/docker-compose/#estructura-de-la-configuracion

Define and manage volumes in Docker Compose
https://docs.docker.com/reference/compose-file/volumes/

Bind mounts
https://docs.docker.com/engine/storage/bind-mounts/

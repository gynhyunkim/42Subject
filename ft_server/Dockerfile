FROM debian:buster

RUN apt-get update &&\
    apt-get install -y nginx \
    openssl \
    php-fpm \
    php-mysql \
    php-mbstring \
    mariadb-server \
    wget \
    vim 

COPY ./srcs/run.sh ./
COPY ./srcs/default ./etc/nginx/sites-available/default
COPY ./srcs/wp-config.php ./tmp
COPY ./srcs/config.inc.php ./tmp

EXPOSE 80 443

CMD  bash run.sh


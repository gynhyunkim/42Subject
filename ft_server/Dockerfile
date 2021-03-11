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

ENV CONF default

COPY ./srcs/run.sh ./
COPY ./srcs/default ./tmp
COPY ./srcs/default_on ./tmp
COPY ./srcs/wp-config.php ./tmp
COPY ./srcs/config.inc.php ./tmp

EXPOSE 80 443

CMD  bash run.sh


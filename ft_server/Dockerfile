FROM debian:latest
RUN apt-get update
RUN apt-get install -y nginx 

WORKDIR /etc/nignx

CMD ["nginx", "-g", "daemon off;"]

EXPOSE 80


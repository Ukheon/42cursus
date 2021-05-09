FROM alpine:latest

RUN apk update \
	&& apk --update --no-cache add \
	nginx \
	openssl

COPY ./run.sh ./
RUN chmod 777 ./run.sh
COPY ./default.conf /etc/nginx/conf.d/

EXPOSE 80 443
RUN ./run.sh
RUN ./usr/sbin/nginx

FROM alpine:3.12

RUN apk update \
	&& apk --update --no-cache add \
	nginx \
	openssl

COPY ./run.sh ./
RUN chmod 777 ./run.sh
COPY ./default.conf /etc/nginx/conf.d/

EXPOSE 80 443
CMD ./run.sh

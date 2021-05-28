FROM	alpine:3.12

RUN		apk update
RUN		apk add nginx
COPY	index.html .
COPY	run.sh .
COPY	nginx.conf ./etc/nginx/.
RUN		apk add openssl
RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Cadet/CN=localhosst" -keyout localhost.dev.key -out localhost.dev.crt
EXPOSE	80 443
CMD		sh ./run.sh

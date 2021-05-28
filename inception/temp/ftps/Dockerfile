FROM	alpine:3.12

RUN		apk update && \
		apk add vsftpd \
		openssl && \
		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Cadet/CN=localhosst" -keyout localhost.dev.key -out localhost.dev.crt
COPY	run.sh .
COPY	vsftpd.conf etc/vsftpd/.
EXPOSE	21 20000-20001
CMD		sh run.sh

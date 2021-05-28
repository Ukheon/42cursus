FROM alpine:3.12

RUN apk update && \
	apk add mysql mysql-client

COPY ./my.cnf /etc/my.cnf
RUN chmod 644 /etc/my.cnf

COPY ./run.sh .
RUN chmod 777 ./run.sh

COPY ./sql .

EXPOSE 3306

cmd sh ./run.sh

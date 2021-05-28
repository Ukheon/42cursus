FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			mariadb-server \
			vim

COPY		./my.cnf ./
COPY		./run.sh ./
EXPOSE		3306
CMD			bash ./run.sh
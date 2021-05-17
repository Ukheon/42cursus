FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			mariadb-server \
			vim \
			php-mysql


COPY		./run.sh ./

CMD			bash run.sh

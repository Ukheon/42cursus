FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			nginx \
			vim \
			openssl \
			php7.3-fpm \
			mariadb-server \
			php-mysql \
			php-mbstring \
			wget

COPY		./srcs/run.sh ./
COPY		./srcs/default ./tmp
COPY		./srcs/config.inc.php ./tmp
COPY		./srcs/wp-config.php ./tmp

EXPOSE		80 443

CMD			bash run.sh

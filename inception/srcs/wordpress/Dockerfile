FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			vim \
			php7.3-fpm \
			php-mbstring 

COPY		./run.sh ./
COPY		./wp-config.php ./tmp

EXPOSE		9000

CMD			bash run.sh

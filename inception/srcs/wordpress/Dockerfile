FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			vim \
			wget \
			php7.3-fpm \
			php-mbstring \
			php-mysql

RUN			mkdir -p /var/www/html/
COPY		./run.sh ./
COPY		./wp-config.php ./tmp/
COPY		./www.conf ./

EXPOSE		9000
CMD			bash ./run.sh
# CMD			["php7.3-fpm", "-F"]

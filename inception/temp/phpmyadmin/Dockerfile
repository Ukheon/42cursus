FROM		alpine:3.12

RUN			apk update && \
			apk add nginx \
			php7 \
			php7-fpm \
			php7-mbstring \
			php7-session \
			php7-common \
			php7-iconv \
			php7-json \
			php7-gd \
			php7-curl \
			php7-xml \
			php7-mysqli \
			php7-imap \
			php7-cgi \
			fcgi \
			php7-pdo \
			php7-pdo_mysql \
			php7-soap \
			php7-xmlrpc \
			php7-posix \
			php7-mcrypt \
			php7-gettext \
			php7-ldap \
			php7-ctype \
			php7-dom && \
			wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz && \
			tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
COPY		nginx.conf ./etc/nginx/
COPY		run.sh .
COPY		config.inc.php .
EXPOSE		5000
CMD			sh run.sh

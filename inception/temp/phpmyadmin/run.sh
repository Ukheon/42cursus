#!/bin/bash

adduser -D -g 'www' www
chown -R www:www /var/lib/nginx
chown -R www:www /var/www
mkdir var/www/html
mv	phpMyAdmin-5.0.2-all-languages phpmyadmin
mv	phpmyadmin var/www/html/
rm	phpMyAdmin-5.0.2-all-languages.tar.gz
mkdir run/nginx
mv	config.inc.php var/www/html/phpmyadmin
php-fpm7
nginx -g "daemon off;"

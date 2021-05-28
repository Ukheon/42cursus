#!/bin/bash

adduser -D -g 'www' www
mkdir var/www/html
chown -R www:www /var/lib/nginx
chown -R www:www /var/www
mv	wordpress var/www/html/
mv	wp-config.php var/www/html/wordpress
chown -R www:www /var/www/html/wordpress
rm latest.tar.gz
mkdir run/nginx
php-fpm7
nginx -g "daemon off;"

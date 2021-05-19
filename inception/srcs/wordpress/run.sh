#/!bin/bash

cp -rp ./tmp/default /etc/nginx/sites-available/default

service php7.3-fpm start
service nginx start

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
rm -rf latest.tar.gz
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./tmp/wp-config.php var/www/html/wordpress/wp-config.php

while : true
do
	sleep 1
done

/bin/bash

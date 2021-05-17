#/!bin/bash

service php7.3-fpm start
echo "CREATE DATABASE wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER 'ukwon'@'%' identified by '1234';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'ukwon'@'%' identified by '1234' WITH GRANT OPTION;" \
	| mysql -u root --skip-password

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
rm -rf latest.tar.gz
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./tmp/wp-config.php var/www/html/wordpress/wp-config.php

sleep 10000000

/bin/bash

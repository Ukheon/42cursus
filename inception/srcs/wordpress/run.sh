#/!bin/bash

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
#mkdir -p /var/www/html/
mv wordpress/ var/www/html/
rm -rf latest.tar.gz
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./tmp/wp-config.php var/www/html/wordpress/wp-config.php
cp -rp ./www.conf /etc/php/7.3/fpm/pool.d/www.conf
# service php7.3-fpm start
# while : true
# do
#     sleep 1
# done
# /bin/bash
# /usr/sbin/php7.3-fpm -F
/etc/init.d/php7.3-fpm start
/etc/init.d/php7.3-fpm stop
/usr/sbin/php-fpm7.3 -F

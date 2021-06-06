#/!bin/bash

# wget https://wordpress.org/latest.tar.gz
# tar -xvf latest.tar.gz
cp -rf ./wordpress/* /var/www/
# mv wordpress/ var/www
cat wp-config | sed s/WORDPRESS_DB_PASSWORD/$WORDPRESS_DB_PASSWORD/ > wp-config.php
cp ./wp-config.php /var/www/wordpress
chown -R www-data:www-data /var/www/wordpress
cp -rp ./www.conf /etc/php/7.3/fpm/pool.d/www.conf
/etc/init.d/php7.3-fpm start
/etc/init.d/php7.3-fpm stop
/usr/sbin/php-fpm7.3 -F

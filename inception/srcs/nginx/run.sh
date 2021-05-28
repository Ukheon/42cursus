#/!bin/bash

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

cp -rp ./tmp/default /etc/nginx/sites-available/default
mkdir -p /var/www/html/
mv wordpress /var/www/html/
# mkdir -p /var/www/html/wordpress
cp -rp ./index.php /var/www/html/wordpress/index.php
cp -rp ./hosts /etc/hosts
echo "<h1>!!!!!!!!! Hi, hello !!!!!!!!!!!!!!!!!!!!  </h1>" >> /var/www/html/wordpress/index.html
echo "<h1> Welcome Ukwon.42.kr  </h1>" >> /var/www/html/index2.html

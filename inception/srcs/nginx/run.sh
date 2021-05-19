#/!bin/bash

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

cp -rp ./tmp/default /etc/nginx/sites-available/default

mkdir -p /var/www/html
echo "<h1>!!!!!!!!! Hi, hello !!!!!!!!!!!!!!!!!!!!  </h1>" >> /var/www/html/index.html
echo "<h1> Welcome Ukwon.42.kr  </h1>" >> /var/www/html/index2.html
service nginx start

while : true
do
	sleep 1
done

/bin/bash

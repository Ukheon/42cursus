#/bin/bash
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

cp -rp ./tmp/default /etc/nginx/sites-available/default

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm -rf phpMyAdmin-5.0.2-all-languages.tar.gz

cp -rp ./tmp/config.sample.php var/www/html/phpmyadmin/config.inc.php

service nginx start
service mysql start
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

chown -R www-data:www-data /var/www/html/wordpress

cp -rp ./tmp/wp-config.php var/www/html/wordpress/wp_config.php

bash



server	{
	listen 443;

	#include    /etc/nginx/fastcgi.conf;

	server_name _;
	ssl on;
	ssl_certificate /etc/ssl/certs/localhost.dev.crt;
	ssl_certificate_key /etc/ssl/private/localhost.dev.key;
	ssl_protocols TLSv1.2 TLSv1.3;
	ssl_ciphers "ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:ECDHE-RSA-AES128-SHA256:ECDHE-RSA-AES256-SHA384";

	root /var/www/html;

	index index.html;

	location /wordpress {
		proxy_pass http://$host:9000;
	}
	location / {
		try_files $uri $uri/ =404;
	}
}



server  {
        listen 9000;

        server_name _;

        root /var/www/html/wordpress;
        index index.php;

        location ~ \.php$ {
                include snippets/fastcgi-php.conf;
                fastcgi_pass unix:/var/run/php/php7.3-fpm.sock;
        }
        location /wordpress {
                return 307 http://$host:9000;
        }
}

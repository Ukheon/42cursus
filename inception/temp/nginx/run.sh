#!/bin/sh

adduser -D -g 'www' www
mkdir /var/www/html
chown -R www:www /var/lib/nginx
chown -R www:www /var/www
mkdir run/nginx
mv index.html var/www/html
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private
nginx -g "daemon off;"

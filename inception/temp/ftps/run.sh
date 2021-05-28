#!/bin/sh

mkdir -p /var/ftp
mkdir -p /var/ftp/admin

adduser -D admin -h /var/ftp/admin
chown admin:admin /var/ftp/admin
echo "admin:admin" | chpasswd

mv localhost.dev.crt etc/ssl/certs/.
mv localhost.dev.key etc/ssl/private/.
vsftpd /etc/vsftpd/vsftpd.conf

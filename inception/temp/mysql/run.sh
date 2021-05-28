#!/bin/sh

mkdir -p /var/run/mysqld
chown -R mysql:mysql /var/run/mysqld

mysql_install_db --user=root
mysqld -u root --bootstrap < sql
mysqld -u root

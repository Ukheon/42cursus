#/!bin/bash

chmod 644 ./my.cnf
cp ./my.cnf ./etc/mysql/my.cnf
chown -R mysql:mysql /var/log/mysql
chown -R mysql:mysql /var/lib/mysql
service mysql start

echo "CREATE DATABASE wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER 'ukwon'@'%' identified by '1234';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'ukwon'@'%' identified by '1234' WITH GRANT OPTION;" \
	| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" \
	| mysql -u root --skip-password
service mysql stop
/usr/bin/mysqld_safe --user=root
# while : true
# do
# 	sleep 1
# done
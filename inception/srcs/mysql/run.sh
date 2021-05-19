#/!bin/bash

cp ./my.cnf ./etc/mysql/my.cnf

service mysql start

echo "CREATE DATABASE wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER 'ukwon'@'%' identified by '1234';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'ukwon'@'%' identified by '1234' WITH GRANT OPTION;" \
	| mysql -u root --skip-password

while : true
do
	sleep 1
done

/bin/bash

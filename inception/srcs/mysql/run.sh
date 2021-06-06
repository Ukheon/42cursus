#/!bin/bash

# cp -rf ./db/* /var/lib/mysql/
chmod 644 ./my.cnf
cp ./my.cnf ./etc/mysql/my.cnf
chown -R mysql:mysql /var/log/mysql
chown -R mysql:mysql /var/lib/mysql
service mysql start
cat .sql | sed s/MYSQL_PASSWORD/$MYSQL_PASSWORD/ > setup.sql
mysql -u root -p$MYSQL_PASSWORD < setup.sql
mysql -u root -p$MYSQL_PASSWORD < data.sql
mysql -u root -p$MYSQL_PASSWORD < password.sql
ps -elf | grep mysql | awk '{print $4}' > a
kill -kill `cat a`
sleep 2
/usr/bin/mysqld_safe --user=root

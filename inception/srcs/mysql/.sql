CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER 'ukwon'@'%' identified by 'MYSQL_PASSWORD'; 
GRANT ALL PRIVILEGES ON wordpress.* TO 'ukwon'@'%' identified by 'MYSQL_PASSWORD' WITH GRANT OPTION;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY 'MYSQL_PASSWORD';
FLUSH PRIVILEGES;
use mysql
update user set plugin='mysql_native_password' where user='root';

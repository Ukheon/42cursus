ALTER USER 'root'@'localhost' IDENTIFIED BY 'MYSQL_PASSWORD';
FLUSH PRIVILEGES;
use mysql
update user set plugin='mysql_native_password' where user='root';
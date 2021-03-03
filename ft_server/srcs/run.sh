#!/bin/bash
chmod 755 /run.sh
chown -R www-data:www-data /var/www/
chmod -R 755 /var/www/

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/O=42Seoul/OU=gkim/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt /etc/ssl/certs/
mv localhost.dev.key /etc/ssl/private/
chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
cp -rp /tmp/wp-config.php /var/www/html/wordpress/

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz

mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
cp -rp /tmp/config.inc.php var/www/html/phpmyadmin/

service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "CREATE USER 'gkim'@'localhost' IDENTIFIED BY 'gkim1234';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'gkim'@'localhost';" | mysql -u root --skip-password
mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password

service nginx start
service php7.3-fpm start
service mysql restart

bash
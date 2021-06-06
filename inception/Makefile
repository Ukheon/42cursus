all:
	docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env up -d --build
set:
	sudo chmod -R 777 srcs
	sudo chmod 777 /var/run/docker.sock
	sudo mkdir /home/ukwon/data/wp
	sudo mkdir /home/ukwon/data/db

rmdir:
	sudo rm -r ../wp
	sudo rm -r ../db

clean:
	docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env down --rmi all

fclean:
	docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env down --rmi all
	sudo rm -r ../wp
	sudo rm -r ../db
	docker volume rm srcs_db
	docker volume rm srcs_wp

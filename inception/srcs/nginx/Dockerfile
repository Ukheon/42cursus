FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			nginx \
			vim \
			openssl

COPY		./run.sh ./
COPY		./default ./tmp
COPY		./index.php ./
COPY		./wordpress/ ./
COPY		./hosts ./

EXPOSE		443
RUN			bash ./run.sh
CMD			["nginx", "-g", "daemon off;"]
# RUN			cp ./hosts /etc/hosts


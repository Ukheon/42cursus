FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			nginx \
			vim \
			openssl \
			wget

COPY		./srcs/run.sh ./

EXPOSE		443

CMD			bash run.sh

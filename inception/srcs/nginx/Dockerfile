FROM		debian:buster

LABEL		maintainer="ukwon@student.42seoul.kr"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			nginx \
			vim \
			openssl

COPY		./run.sh ./
COPY		./default ./tmp


EXPOSE		443

CMD			bash run.sh

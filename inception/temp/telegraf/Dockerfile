FROM alpine:3.12

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_static_linux_amd64.tar.gz
RUN tar -xvf telegraf-1.15.3_static_linux_amd64.tar.gz
RUN cp -r telegraf-1.15.3/* .

COPY ./telegraf.conf /etc/telegraf/.
COPY ./run.sh .

CMD sh run.sh

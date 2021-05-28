FROM alpine:3.12

RUN apk update && apk add influxdb
COPY influxdb.conf etc/.
COPY run.sh .

EXPOSE 8086
CMD sh run.sh

FROM	alpine:3.12

RUN		apk update && apk upgrade && apk add grafana --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted
COPY	run.sh .
COPY	custom.ini /usr/share/grafana/conf/.
COPY	dashboard.yaml /usr/share/grafana/conf/provisioning/dashboards/.
COPY	dashboards /var/lib/grafana/dashboards
COPY	influxdb.yaml /usr/share/grafana/conf/provisioning/datasources/.
CMD		sh run.sh

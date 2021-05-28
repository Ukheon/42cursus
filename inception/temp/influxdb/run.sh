#!/bin/sh

influxd -config /etc/influxdb.conf & sleep 5

influx -execute "CREATE DATABASE telegraf"
influx -execute "CREATE USER admin WITH PASSWORD 'admin'"
influx -execute "GRANT ALL ON telegraf TO admin"

sleep infinity

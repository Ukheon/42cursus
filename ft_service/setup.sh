#!/bin/bash

minikube start --driver=virtualbox
eval $(minikube docker-env)
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
#kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
kubectl create -f metallb-config.yaml

cd ./srcs/nginx
docker build -t nginx
kubectl apply -f ./nginx.yaml

cd ../mysql
docker build -t mysql
kubectl apply -f ./nginx.yaml

cd ../wordpress
docker build -t wordpress
kubectl apply -f ./wordpress.yaml

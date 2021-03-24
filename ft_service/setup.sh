#!/bin/bash

minikube start --driver=virtualbox
eval $(minikube docker-env)
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
kubectl create -f metallb-config.yaml

cd ./srcs/nginx
echo "\033[32mnginx image build\033[0m"
docker build -t nginx:latest .
echo "\033[36mnginx deployment\033[0m"
kubectl apply -f ./nginx.yaml

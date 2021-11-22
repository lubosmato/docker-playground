#!/bin/bash

for value in Martin Mišo Aďo Radek Pavel Ondra Peťa Dávid Ota
do
openssl req -newkey rsa:4096 \
            -x509 \
            -sha256 \
            -days 3650 \
            -nodes \
            -out ${value}.crt \
            -keyout ${value}.key \
            -subj "/C=CZ/ST=/L=/O=/CN=www.zdur-pyco.com"
done

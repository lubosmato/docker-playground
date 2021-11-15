FROM alpine

WORKDIR /home/hello-world/

COPY ./main.sh ./

ENTRYPOINT ["/bin/sh"]
CMD ["main.sh"]

# docker build . -t helloworld:latest
# docker run -it helloworld:latest

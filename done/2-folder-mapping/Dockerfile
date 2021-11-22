FROM alpine

WORKDIR /home/folder-mapping/

COPY ./main.sh ./

ENTRYPOINT ["/bin/sh"]
CMD ["main.sh"]

# docker build . -t foldermapping:latest
# docker run -it --mount type=bind,source=D:/code/docker-playground/folder-mapping/file.txt,target=/home/folder-mapping/file.txt foldermapping:latest

FROM node:latest

WORKDIR /app
COPY app.js ./
COPY package.json ./
COPY yarn.lock ./

# install dependencies
RUN yarn

ENTRYPOINT ["node"]
CMD ["app.js"]

# docker build . -t backend:latest
# docker network create -d bridge mydockernetwork
# docker run -it -p 3000:3000 --network=mydockernetwork backend:latest

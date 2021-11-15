FROM node:latest

WORKDIR /app
COPY app.js ./
COPY package.json ./
COPY yarn.lock ./

# install dependencies
RUN yarn

ENTRYPOINT ["node"]
CMD ["app.js"]

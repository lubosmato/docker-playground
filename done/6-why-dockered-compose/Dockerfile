# frontend builder image
FROM node:lts-alpine as frontend-builder

WORKDIR /frontend/
COPY ./frontend/ /frontend/
RUN rm -rf /app/node_modules/

RUN \
  yarn && \
  yarn build

FROM nginx:latest

WORKDIR /app
COPY --from=frontend-builder /frontend/dist/ /app/

COPY ./nginx.conf /etc/nginx/conf.d/default.conf

FROM alpine:latest

WORKDIR /app
COPY . /app

RUN \
  apk update && \
  apk --no-cache add cmake clang clang-dev make gcc g++ libc-dev linux-headers poco-dev

RUN \
  mkdir -p /app/build && \
  cd /app/build && \
  cmake .. && \
  cmake --build .

CMD ["/app/build/fast_compute_service"]

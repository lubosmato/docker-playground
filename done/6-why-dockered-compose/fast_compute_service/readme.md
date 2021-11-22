It runs http server on port 8080 and accepts POST request with a number in request body. Response is fibonacci number.

```bash
curl -X POST -d '42' http://127.0.0.1:8080/
# 267914296
```

To build:

```bash
sudo apt-get install -y libpoco-dev # Windows users have fun
cd build
cmake ..
cmake --build .
```

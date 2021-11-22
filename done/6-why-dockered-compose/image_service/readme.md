It runs http server on port 8081 and accepts POST request with a number in request body. Response is base64 encoded jpeg image. On image a fibonacci number will be drawn and the number is computed by `fast_compute_service`. 

```bash
curl -X POST -d '42' http://127.0.0.1:8081/
# /9j/4AAQSkZJRgABAQAAAQABAAD/2wBDAAIBAQEBAQIBAQECAgICAgQ...
```

How to run:

```bash
python compute_engine.py
```

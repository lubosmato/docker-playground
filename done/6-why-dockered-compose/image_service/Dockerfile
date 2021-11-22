FROM python:latest

WORKDIR /app
COPY ./ /app

RUN apt-get update && apt-get install -y python3-opencv
RUN pip install -r requirements.txt

ENTRYPOINT ["python"]
CMD ["compute_engine.py"]

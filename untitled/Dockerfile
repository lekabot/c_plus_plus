FROM alpine:latest

RUN apk update && \
    apk add valgrind

WORKDIR /usr/src/app

COPY . /usr/src/app

CMD ["valgrind", "--tool=memcheck", "--leak-check=yes", "test"]

# docker build -t valgrind_container .
# docker run -it valgrind_container

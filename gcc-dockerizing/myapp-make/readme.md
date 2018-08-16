# docker - gcc

## Start a GCC instance running your app

``` dockerfile
FROM gcc:4.9
COPY . /usr/src/myapp-make
WORKDIR /usr/src/myapp-make
RUN make
CMD [ "./hider_msg" ]
```

docker build

``` shell
$ docker build -t my-gcc-app-make .
```

docker run

``` shell
$ docker run -it --rm --name my-running-app-make my-gcc-app-make
```

## Compile your app inside the Docker container

To build via makefile

``` shell
$ docker run --rm -v "$PWD":/usr/src/myapp-make -w /usr/src/myapp-make gcc:4.9 make
```

# docker - gcc

## Start a GCC instance running your app

``` dockerfile
FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o myapp main.c
CMD ["./myapp"]
```

docker build

``` shell
$ docker build -t my-gcc-app .
```

docker run

``` shell
$ docker run -it --rm --name my-running-app my-gcc-app
```

## Compile your app inside the Docker container

To compile, but not run your app inside the Docker instance

``` shell
$ docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 gcc -o myapp myapp.c
```

To build via makefile

``` shell
$ docker run --rm -v "$PWD":/usr/src/myapp-make -w /usr/src/myapp-make gcc:4.9 make
```

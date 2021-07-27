# Using Docker to Cross-Compile with ev3dev cross-compiler image

* https://www.ev3dev.org/docs/tutorials/using-docker-to-cross-compile/
* https://www.ev3dev.org/docs/tutorials/getting-started-with-c/

## Install

Download the ev3dev cross-compiler image

```
docker pull ev3dev/debian-jessie-cross
```

When it is finished, we can give it a shorter name

```
docker tag ev3dev/debian-jessie-cross ev3cc
```

>  Docker images are immutable. You can always revert back to this image after making changes without having to download it again.

You can see a list of images you have downloaded by running

```
$ docker images

REPOSITORY                   TAG                 IMAGE ID            CREATED             SIZE
ev3dev/debian-jessie-cross   latest              d6ccb79c68c5        20 months ago       649MB
ev3cc                        latest              d6ccb79c68c5        20 months ago       649MB
```

and delete them with

```
docker rmi <image-name-or-hash>
```

## Usage

Now, we compile using the docker image.

### Docker Toolbox
Unless you are using Windows 10 Pro edition, you may have received the following error when trying to install Docker using Install `Docker.msi`:

```
HyperV is not available on home editions. Please use Docker Toolbox.
```

This is fine, you can just download Docker Toolbox instead.

Docker Toolbox however handles shared drives differently; there is no whale icon in the system tray. Instead, Docker Toolbox automatically allows sharing of your `C:\Users\myname` folder. Also, the path handling is different, you have to use paths in linux style, so the command below has to be changed:

```
docker run --rm --it -v /c/Users/myname/example/:/src -w /src ev3cc
```

We run a new docker container.

```
docker run --rm -it -v /c/Users/webnl/Documents/_workspace/loggar-c/gcc-dockerizing/ev3dev/:/app -w /app ev3cc
```

* `run` means we are running a new container.
* `--rm` indicates that we want to throw away the container when we are done. If you don’t do this, docker saves a new container from each run command, which takes up space on your hard drive.
* `-it` is two options, it means “interactive” and “tty”. This will let us use the command prompt inside of the container.
* `-v` <host-path>:<container-path> lets us use a directory from our host computer inside of the container.
* `-w` <container-path> is the working directory inside of the container.
* `ev3cc` is the name of the docker image we are using.

Now we can compile our program.

```
mkdir .output
```

```
arm-linux-gnueabi-gcc -o ./.output/hello ./src/hello.c
```

> Note: For BeagleBone and Raspberry Pi 2/3 use `gnueabihf` instead of `gnueabi`.

Since this program does not depend on any hardware drivers, we can actually run this program inside of the Docker container! There are some caveats though… You must be running Docker >= 1.12 and if you are using a Linux host you must have the proper format registered with `binfmt_misc`.

```
./hello
```

Also, a binary file called `hello` will now exist in `C:\path\to\host` on your host computer. You can copy this file to your EV3 and run it!

To exit the docker container, simply type:

```
exit
```

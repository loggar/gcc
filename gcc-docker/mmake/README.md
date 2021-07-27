# C Build environment in a docker container

refs)

* https://github.com/nachoparker/mmake
* https://ownyourbits.com/2017/06/20/c-build-environment-in-a-docker-container/

C Build environment in a docker container, featuring colored output and compiler cache

## Features

 - GCC 6
 - `ccache` for fast recompilation
 - `colorgcc` for colored output
 - Support for cross-compiling with external toolchain
 - Very small: 240 MB including the base `ownyourbits/minidebian` ( ~50 MB )

## Usage

### Compilation

It is recommended to use this alias

```
alias mmake='docker run --rm -v "$(pwd):/src" -t ownyourbits/mmake'
```

Then, use it just as you would use 'make'

```
cd test
mmake
```

You can pass Makefile targets and variables the usual way

```
mmake alltargets CFLAGS=-g -j5
```

A `.ccache` directory will be generated in the directory of execution to speed up subsequent compilations.

Note that the container only includes the generic libraries, so if you need to use some external libraries for your project, you will need to extend the container.

For instance, if you need to link against the ncurses library it will naturally fail

```
$ mmake
cc main.c -lncurses -o main
main.c:5:1: warning: return type defaults to `int' [-Wimplicit-int]
main()
^~~~
/usr/bin/ld: cannot find -lncurses
collect2: error: ld returned 1 exit status
Makefile:3: recipe for target 'world' failed
make: *** [world] Error 1
```

You need to install it first. Just create another layer on top of mmake

``` dockerfile
FROM ownyourbits/mmake
 
RUN sudo apt-get update; sudo apt-get install -y libncurses5-dev
```

### Cross-Compilation

Adjust to the path to your toolchain directory

```
alias xmake='docker run --rm -v "$(pwd):/src" -v "/toolchain/path:/toolchain" -t ownyourbits/xmake'
```

Then, use it just as you would use 'make'

```
cd test
xmake
```

If we now inspect the file, we can see that we are crosscompiling the same C code, in the same folder just by invoking xmake instead of mmake. Nice!

```
$ file main
main: ELF 32-bit MSB executable, MIPS, MIPS32 rel2 version 1 (SYSV), dynamically linked, interpreter /lib/ld-musl-mips-sf.so.1, with debug_info, not stripped
```

We now have a MIPS version of main.

The output will still be colored, but if you want to use ccache, you have to include it in the toolchain it and set it up for your particular case.

Check out this collection of ready to use toolchains from free-electrons.

## Notes

A `.ccache` directory will be generated in the directory of execution

To avoid the delay in the creation and deletion of the conttainer, you can leave the container running for faster execution. Use these aliases

```
alias runmake='docker run --rm -d -v "$(pwd):/src" --entrypoint /bg.sh -t --name mmake ownyourbits/mmake'
alias mmake='docker exec -t mmake /run.sh'
```

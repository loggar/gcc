## including dynamic libraries

compile libraries

```
gcc -I./includes -c ./includes/mycal.c -o ./includes/mycal.o
```

compile test program

```
gcc -I./includes -c test_code.c -o test_code.o
```

create an archive library from mycal.o and store it in `./lib`

```
ar -rcs ./libs/libmycal.a ./includes/mycal.o
```

compile the excutable

```
gcc test_code.o -L./libs -lmycal -o test_code
```

### link archive-libraries at runtime

create an object file

```
gcc -I./includes -fPIC -c ./includes/mycal.c -o ./fpic/mycal.o
./includes/mycal.c:1:0: warning: -fPIC ignored for target (all code is position independent)
 #include <stdio.h>
 ^
```

`-fPIC` tells gcc that you want to create position-independent code.

Position-independent code is code that doesn't mind where the computer loads it into memory.

You can ignore this option on Windows system.


create an dynamic library

```
gcc -shared ./fpic/mycal.o -o ./libs-fpic/mycal.dll (MinGW on Windows)
gcc -shared ./fpic/mycal.o -o ./libs-fpic/mycal.dll.a (Cygwin on Windows)
gcc -shared ./fpic/mycal.o -o ./libs-fpic/mycal.so (Linux/Unix)
gcc -shared ./fpic/mycal.o -o ./libs-fpic/mycal.dylib (Mac)
```

compile the executable

```
gcc -I./includes -c test_code.c -o test_code.o

gcc test_code.o -L./libs-fpic -lmycal -o test_code
```

execute

```
(MinGW on Windiws)
set PATH=%PATH%;./libs-fpic
test_code
Weight: 115.20 lbs
Distance: 11.30 miles
Calories burned: $4.2f cal

(Cygwin on Windows)
PATH="$PATH:./libs-fpic"
./test_code

(on Linux)
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs-fpic
./test_code

(on Mac)
./test_code
```

On the Mac, you can just run the program. When the program is compiled on the Mac, the full path to the `mycal.dylib` file is stored inside the executable, so when the program starts, it knows exactly where to find the library.


Now, you want to replace the lib file dynamically with `includes/mycal.uk.c` file.

create new object file

```
gcc -I./includes -fPIC -c ./includes/mycal.uk.c -o ./fpic/mycal.o
```

create new dynamic library

```
gcc -shared ./fpic/mycal.o -o ./libs-fpic/mycal.dll
```

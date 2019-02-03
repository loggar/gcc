# Charly

## C

Ref)

headfirst c (https://github.com/dogriffiths/HeadFirstC)

practice-c/functional-pointer (https://www.geeksforgeeks.org/function-pointer-in-c)

## mingw

show gcc configurations and include paths

```
λ gcc -v -E -x c++ nul

Using built-in specs.
COLLECT_GCC=gcc
Target: mingw32
Configured with: ../src/gcc-5.3.0/configure --build=x86_64-pc-linux-gnu --host=mingw32 --prefix=/mingw --disable-win32-registry --target=mingw32 --with-arch=i586 --enable-languages=c,c++,objc,obj-c++,fortran,ada --enable-static --enable-shared --enable-threads --with-dwarf2 --disable-sjlj-exceptions --enable-version-specific-runtime-libs --with-libintl-prefix=/mingw --enable-libstdcxx-debug --with-tune=generic --enable-libgomp --disable-libvtv --enable-nls : (reconfigured) ../src/gcc-5.3.0/configure --build=x86_64-pc-linux-gnu --host=mingw32 --prefix=/mingw --disable-win32-registry --target=mingw32 --with-arch=i586 --enable-languages=c,c++,objc,obj-c++,fortran,ada --enable-static --enable-shared --enable-threads --with-dwarf2 --disable-sjlj-exceptions --enable-version-specific-runtime-libs --with-libiconv-prefix=/mingw --with-libintl-prefix=/mingw --enable-libstdcxx-debug --with-tune=generic --enable-libgomp --disable-libvtv --enable-nls
Thread model: win32
gcc version 5.3.0 (GCC)
COLLECT_GCC_OPTIONS='-v' '-E' '-mtune=generic' '-march=i586'
 c:/_dev/mingw/bin/../libexec/gcc/mingw32/5.3.0/cc1plus.exe -E -quiet -v -iprefix c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/ nul -mtune=generic -march=i586
ignoring duplicate directory "c:/_dev/mingw/lib/gcc/../../lib/gcc/mingw32/5.3.0/include/c++"
ignoring duplicate directory "c:/_dev/mingw/lib/gcc/../../lib/gcc/mingw32/5.3.0/include/c++/mingw32"
ignoring duplicate directory "c:/_dev/mingw/lib/gcc/../../lib/gcc/mingw32/5.3.0/include/c++/backward"
ignoring duplicate directory "c:/_dev/mingw/lib/gcc/../../lib/gcc/mingw32/5.3.0/include"
ignoring nonexistent directory "/mingw/include"
ignoring duplicate directory "c:/_dev/mingw/lib/gcc/../../include"
ignoring duplicate directory "c:/_dev/mingw/lib/gcc/../../lib/gcc/mingw32/5.3.0/include-fixed"
ignoring duplicate directory "c:/_dev/mingw/lib/gcc/../../lib/gcc/mingw32/5.3.0/../../../../mingw32/include"
ignoring nonexistent directory "/mingw/include"
#include "..." search starts here:
#include <...> search starts here:
 c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/include/c++
 c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/include/c++/mingw32
 c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/include/c++/backward
 c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/include
 c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/../../../../include
 c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/include-fixed
 c:\_dev\mingw\bin\../lib/gcc/mingw32/5.3.0/../../../../mingw32/include
End of search list.
# 1 "nul"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "nul"
COMPILER_PATH=c:/_dev/mingw/bin/../libexec/gcc/mingw32/5.3.0/;c:/_dev/mingw/bin/../libexec/gcc/;c:/_dev/mingw/bin/../lib/gcc/mingw32/5.3.0/../../../../mingw32/bin/
LIBRARY_PATH=c:/_dev/mingw/bin/../lib/gcc/mingw32/5.3.0/;c:/_dev/mingw/bin/../lib/gcc/;c:/_dev/mingw/bin/../lib/gcc/mingw32/5.3.0/../../../../mingw32/lib/;c:/_dev/mingw/bin/../lib/gcc/mingw32/5.3.0/../../../
COLLECT_GCC_OPTIONS='-v' '-E' '-mtune=generic' '-march=i586'
```
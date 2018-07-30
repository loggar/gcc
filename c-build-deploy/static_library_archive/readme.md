## including static archive-libraries

archive command `ar` will store a set of object files in an archive file:

```
ar -rcs libmysecurity.a encrypt.o checksum.o
```

options mean 

```
-r : .a file will be updated if it already exists
-c : the archive will be created without any feedback
-s : create an index at the start of the .a file
```

check the archive file

```
λ nm libmysecurity.a

encrypt.o:
00000000 b .bss
00000000 d .data
00000000 r .eh_frame
00000000 r .rdata$zzz
00000000 t .text
00000000 T _encrypt

checksum.o:
00000000 b .bss
00000000 d .data
00000000 r .eh_frame
00000000 r .rdata$zzz
00000000 t .text
00000000 T _checksum
```


compile test executable

```
gcc test_code.c -L./custom-lib -lmysecurity -o test_code
```

## including static libraries

with custom lib directory

```
gcc -I./custom-lib test_code.c ./custom-lib/encrypt.o ./custom-lib/checksum.o -o test_code
```
## including multiple sources

compile multiple sources

```
λ gcc -c encrypt.c -o encrypt.o

λ gcc -c checksum.c -o checksum.o
```

compile the test executable

```
λ gcc test_code.c encrypt.o checksum.o -o test_code

λ test_code
Encrypted to 'Loz~t?ymvzq{?~q{?zqkzm'
Checksum is 89561741
Decrypted back to 'Speak friend and enter'
Checksum is 89548156
```

with custom lib directory

```
gcc -I./custom-lib test_code.c ./custom-lib/encrypt.o ./custom-lib/checksum.o -o test_code
```
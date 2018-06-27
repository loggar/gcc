# File descriptor table

## stdout stderr

| # | Data Stream |
|---|-------------|
| 0 | keyboard    |
| 1 | screen      |
| 2 | screen      |

```
./myprogram > output.txt 2> errors.log
```

| # | Data Stream |
|---|-------------|
| 0 | keyboard    |
| 1 | screen      |
| 2 | errors.log  |

## dup2()

| # | Data Stream |
|---|-------------|
| 0 | keyboard    |
| 1 | screen      |
| 2 | errors.log  |
| 3 | a.txt       |
| 4 | b.txt       |

```
dup2(4,3)
```

| # | Data Stream |
|---|-------------|
| 0 | keyboard    |
| 1 | screen      |
| 2 | errors.log  |
| 3 | b.txt       |
| 4 | b.txt       |

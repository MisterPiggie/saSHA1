# saSHA1

A SHA-1 implementation written from scratch in C, no external crypto dependencies.

## Correctness

`test.c` checks output against OpenSSL's `SHA1()` — same input, same
20-byte digest.

## API

​```c
void SHA1_hash(const unsigned char *message, size_t length, uint8_t hash[20]);
​```

Pass a buffer and its length; `hash` gets filled with the 20-byte digest.

## Internal funcs

```c
//padding
uint8_t *SHA1_padding(const unsigned char *message, size_t length, size_t *padded_length);

//compression
void SHA1_compress_blocks(uint8_t *padded_buf, uint32_t *A, uint32_t *B, uint32_t *C, uint32_t *D, uint32_t *E);

//helper funcs
uint32_t rotate_left (uint32_t word, int n);
void get_f_and_k_values(int i, uint32_t B_temp, uint32_t C_temp, uint32_t D_temp, uint32_t *k, uint32_t *f_result);
```

## Usage

​```c
#include "SHA1.h"

uint8_t digest[20];
const char *msg = "Testing hashing";
SHA1_hash((unsigned char *)msg, strlen(msg), digest);

for (int i = 0; i < 20; i++) printf("%02x", digest[i]);
​```

## Test
​```
gcc -Wall -o test test.c SHA1.c -lssl -lcrypto
./test
​```
Comparing to OpenSSL version

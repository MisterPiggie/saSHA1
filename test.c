#include <stdint.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include "SHA1.h"


int main(void)
{
    uint8_t hash[20];
    uint8_t ssl_hash[20];
    char *str = "Testing hashing";
    SHA1_hash((unsigned char *)str, strlen(str), hash);
    SHA1((unsigned char *)str, strlen(str), ssl_hash);

    printf("SHA1 of string \"%s\" from SSL: ", str);
    for(int i = 0; i < 20; i++) {
        printf("%02x", ssl_hash[i]);
    }

    printf("\n");

    printf("SHA1 of string\"%s\" from implementation: ", str);
    for(int i = 0; i < 20; i++) {
        printf("%02x", hash[i]);
    }

    printf("\n");

    return 0;
}  

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ECB 1

#include "aes.h"

static void phex(uint8_t* str);
static void test_encrypt_ecb_verbose(void);

int main()
{
    test_encrypt_ecb_verbose();
    return 0;
}

//将字符串转化为十六进制
static void phex(uint8_t* str)
{
    unsigned char i;
    for(i = 0; i < 16; ++i)
        printf("%.2x", str[i]);
    printf("\n");
}

static void test_encrypt_ecb_verbose(void)
{
    uint8_t i, buf[64], buf2[64];
    //密钥
    uint8_t key[16] =        { (uint8_t) 0x13, (uint8_t) 0x57, (uint8_t) 0x9b, (uint8_t) 0xdf, (uint8_t) 0x02, (uint8_t) 0x46, (uint8_t) 0x8a, (uint8_t) 0xce, (uint8_t) 0x12, (uint8_t) 0x34, (uint8_t) 0x56, (uint8_t) 0x78, (uint8_t) 0x90, (uint8_t) 0xab, (uint8_t) 0xcd, (uint8_t) 0xef };
    //明文
    uint8_t plain_text[64] = { (uint8_t) 0x11, (uint8_t) 0x22, (uint8_t) 0x33, (uint8_t) 0x44, (uint8_t) 0x55, (uint8_t) 0x66, (uint8_t) 0x77, (uint8_t) 0x88, (uint8_t) 0x99, (uint8_t) 0x00, (uint8_t) 0xaa, (uint8_t) 0xbb, (uint8_t) 0xcc, (uint8_t) 0xdd, (uint8_t) 0xee, (uint8_t) 0xff };

    memset(buf, 0, 64);
    memset(buf2, 0, 64);

    printf("明文:\n");
    for(i = (uint8_t) 0; i < (uint8_t) 1; ++i)
    {
        phex(plain_text + i * (uint8_t) 16);
    }
    printf("\n");

    printf("密钥:\n");
    phex(key);
    printf("\n");


    printf("加密后明文:\n");
    AES128_ECB_encrypt(plain_text , key, buf);
        phex(buf);
    printf("\n");
}

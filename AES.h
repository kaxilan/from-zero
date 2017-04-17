#ifndef _AES_H_
#define _AES_H_
#include <stdint.h>
#ifndef ECB
  #define ECB 1
#endif

#if defined(ECB) && ECB

void AES128_ECB_encrypt(const uint8_t* input, const uint8_t* key, uint8_t *output);
void AES128_ECB_decrypt(const uint8_t* input, const uint8_t* key, uint8_t *output);

#endif // #if defined(ECB) && ECB

#endif //_AES_H_

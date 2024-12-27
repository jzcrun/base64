
#ifndef __GW_BASE64_H
#define __GW_BASE64_H

#include <stdio.h>
#include <stdlib.h>

// 编码函数
void base64_encode(const unsigned char *input, int inputlength, char *output);

// 解码函数 
void base64_decode(const char *input, unsigned char *output);

#endif


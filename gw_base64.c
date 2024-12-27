#include "gw_base64.h"

// 用于Base64编码的字符表
const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// 编码函数
void base64_encode(const unsigned char *input, int input_length, char *output) {
    int i, j;
    unsigned char a, b, c;
    int index = 0;

    for (i = 0; i < input_length; i += 3) {
        a = input[i];
        b = (i + 1 < input_length)? input[i + 1] : 0;
        c = (i + 2 < input_length)? input[i + 2] : 0;

        output[index++] = base64_table[a >> 2];
        output[index++] = base64_table[((a & 3) << 4) | (b >> 4)];
        output[index++] = (i + 1 < input_length)? base64_table[((b & 15) << 2) | (c >> 6)] : '=';
        output[index++] = (i + 2 < input_length)? base64_table[c & 63] : '=';
    }
    output[index] = '\0';
}

// 解码函数
void base64_decode(const char *input, unsigned char *output) {
    int i, j;
    unsigned char a, b, c, d;
    int index = 0;

    for (i = 0; input[i]!= '\0'; i += 4) {
        for (j = 0; j < 64; j++) {
            if (base64_table[j] == input[i])
                a = j;
            if (base64_table[j] == input[i + 1])
                b = j;
            if (input[i + 2]!= '=') {
                if (base64_table[j] == input[i + 2])
                    c = j;
            }
            if (input[i + 3]!= '=') {
                if (base64_table[j] == input[i + 3])
                    d = j;
            }
        }
        output[index++] = (a << 2) | (b >> 4);
        if (input[i + 2]!= '=')
            output[index++] = ((b & 15) << 4) | (c >> 2);
        if (input[i + 3]!= '=')
            output[index++] = ((c & 3) << 6) | d;
    }
    output[index] = '\0';
}



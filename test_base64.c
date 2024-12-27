#include "gw_base64.h"

int main() {
    // 编码测试
    unsigned char input[] = "Hello, World!";
    char encoded[100];
    base64_encode(input, sizeof(input) - 1, encoded);
    printf("Encoded: %s\n", encoded);

    // 解码测试
    unsigned char decoded[100];
    base64_decode(encoded, decoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}

#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binHex (char *src, char *dst, size_t max);
void hexBin (char *src, char *dst, size_t max);

void binHex(char src[], char dst[], size_t max)
{
    int len = strlen(src);
    int hexIndex = 0;

    //Padding if binary number is not multiple of 4
    int padding = len % 4;
    if (padding != 0) {
        padding = 4 - padding;
        for (int i = 0; i < padding; i++) {
            src[len + i] = '0';
        }
        len += padding;
    }

    for (int i = 0; i < len; i += 4) {
        int num = 0;
        for (int j = 0; j < 4; j++) {
            num = num * 2 + (src[i + j] - '0');
        }
        if (num <= 9) {
            dst[hexIndex++] = num + '0';
        } else {
            dst[hexIndex++] = num - 10 + 'a';
        }
    }

    // Adding null character at the end
    dst[hexIndex] = '\0';
}

    

void hexBin(char src[], char dst[], size_t max)
{
  size_t i = (src[1] == 'x' || src[1] == 'X')? 2 : 0;
 
    while (src[i]) {
 
        switch (src[i]) {
        case '0':
            strcat(dst, "0000");
            break;
        case '1':
            strcat(dst,"0001");
            break;
        case '2':
            strcat(dst,"0010");
            break;
        case '3':
            strcat(dst,"0011");
            break;
        case '4':
            strcat(dst,"0100");
            break;
        case '5':
            strcat(dst,"0101");
            break;
        case '6':
            strcat(dst,"0110");
            break;
        case '7':
            strcat(dst,"0111");
            break;
        case '8':
            strcat(dst,"1000");
            break;
        case '9':
            strcat(dst, "1001");
            break;
        case 'A':
        case 'a':
            strcat(dst, "1010");
            break;
        case 'B':
        case 'b':
            strcat(dst, "1011");
            break;
        case 'C':
        case 'c':
            strcat(dst, "1100");
            break;
        case 'D':
        case 'd':
            strcat(dst, "1101");
            break;
        case 'E':
        case 'e':
            strcat(dst, "1110");
            break;
        case 'F':
        case 'f':
            strcat(dst, "1111");
            break;
        }
        i++;
    }

}

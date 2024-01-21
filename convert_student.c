#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binHex (char *src, char *dst, size_t max);
void hexBin (char *src, char *dst, size_t max);

void binHex(char src[], char dst[], size_t max)
{
    size_t i = 0;
    int j = 0;
    while (src[i] != '\0' && src[i] != '\n') {
        char temp[] = {src[i], src[i + 1], src[i + 2], src[i + 3], '\0'};
        int decimal = strtol(temp, NULL, 2);
        if (decimal >= 10 && decimal <= 15) {
            sprintf(dst + j, "%x", decimal); // lowercase hexadecimal format
        } else {
            sprintf(dst + j, "%X", decimal); // uppercase hexadecimal format
        }
        i += 4;
        j++;
    }
    dst[j] = '\0';
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

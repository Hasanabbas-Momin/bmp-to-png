#include "png_ds.h"
#include"bmp_ds_new.h"
#include "header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
// #include"Read_BMP.h"
#include "zlib.h"

void BMP_TO_PNG();                                          
// unsigned int crc32c(unsigned char *message) {        // initial crc
//    int i, j;
//    unsigned int byte, crc, mask;

//    i = 0;
//    crc = 0xFFFFFFFF;
//    while (message[i] != 0) {
//       byte = message[i];            // Get next byte.
//       crc = crc ^ byte;
//       for (j = 7; j >= 0; j--) {    // Do eight times.
//          mask = -(crc & 1);
//          crc = (crc >> 1) ^ (0xEDB88320 & mask);
//       }
//       i = i + 1;
//    }
//    return ~crc;
// }

int main(){


    
   

    


    
   
   

    char s[20];
    scanf("%s", s);
    Read_BMPfile(s);
    BMP_TO_PNG();
    writepng(h1, I1, end);
    freeimagedata(image);
}
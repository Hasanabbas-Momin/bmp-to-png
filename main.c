#include "png_ds.h"
#include"bmp_ds_new.h"
#include "header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
// #include"Read_BMP.h"


void BMP_TO_PNG();
unsigned int crc32c(unsigned char *message) {
   int i, j;
   unsigned int byte, crc, mask;

   i = 0;
   crc = 0xFFFFFFFF;
   while (message[i] != 0) {
      byte = message[i];            // Get next byte.
      crc = crc ^ byte;
      for (j = 7; j >= 0; j--) {    // Do eight times.
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
      i = i + 1;
   }
   return ~crc;
}

int main(){

    struct IDAT{
    
    unsigned int size;
    char str[4];//should be "IDAT"
   //  struct GRAYSCALE **graycolor;
    // unsigned char pixels;
    struct GRAYSCALE arr[img_info.height][img_info.width];
    unsigned int crc;
    };



   struct IDAT I2;
   for(int i=0;i<(img_info.height);i++)
   {
      for (int j = 0;j<(img_info.width); j++)
         I2.arr[i][j] = image.graycolor[i][j];
   }
    
    
    I2.size = reverse(img_info.header_size);
    // I2.str = "IDAT";
    strcpy(I2.str, "IDAT");
    char *d= (char *)&I2;
    I2.crc= reverse(crc32c(d));
    

    char s[20];
    // scanf("%s", s);
    Read_BMPfile("source.bmp");
    BMP_TO_PNG();
    writepng(h1, I1, end, I2.crc);
    freeimagedata(image);
}
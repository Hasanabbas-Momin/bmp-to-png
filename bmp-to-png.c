// #include "bmp_ds_new.h"
#include "png_ds.h"
#include"bmp_ds_new.h"
#include "header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

unsigned int crc32b(unsigned char *message);

struct HEADER h1;
struct IHDR I1;
struct IDAT I2;
struct IEND end;
void BMP_TO_PNG()
{
    // struct IMAGE picture_data;
    // freeimagedata(picture_data);

    h1.arr[0] = 137;
    h1.arr[1] = 80;
    h1.arr[2] = 78;
    h1.arr[3] = 71;
    h1.arr[4] = 13;
    h1.arr[5] = 10;
    h1.arr[6] = 26;
    h1.arr[7] = 10;
    // h1.first_byte = 137;
    // // h1.PNG_SIGN[3] = "PNG";
    // strcpy(h1.PNG_SIGN, "PNG");
    // h1.random1 = 3338;
    // h1.random2 = 26;
    // h1.random3 = 10;
    // char *b= (char *)&h1;
    // h1.crc= crc32b(b);
    
    
    // I1.size = Read_BMPfile.bmp.hdr.file_size;     // this is equal to 13 so no need to take it
    I1.size = reverse(13);
    // I1.str = "IHDR";
    strcpy(I1.str, "IHDR");
    I1.width = reverse(img_info.width);
    // printf("\n%i", I1.width);
    I1.height = reverse(img_info.height);
    // printf("\n%i", I1.height);
    I1.bit_depth = 8;
    I1.colour_type = 0;
    I1.cm = 0;
    I1.fm = 0;
    I1.im = 0;
    char *c= (char *)&I1;
    I1.crc= reverse(crc32b(c));

    
    I2.size = reverse(img_info.header_size);
    // I2.str = "IDAT";
    strcpy(I2.str, "IDAT");
    char *d= (char *)&image.graycolor;
    I2.crc= reverse(crc32b(d));
    

    // IEND[] = {"I", "E", "N", "D"};
    strcpy(end.iend, "IEND");
    char *e= (char *)&end;
    end.crc= reverse(crc32b(e));
}


unsigned int crc32b(unsigned char *message) {
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

    

// int conversion()
// {
//     IHDR.str = "IHDR";
//     IHDR.width = BMP.b_img_info.width                // change BMP to the name of struct
//     IHDR.height = BMP.b_img_info.height              // change IHDR to struct name
//     IHDR.bit_depth = 8;
//     IHDR.colour_type = 0;
//     IHDR.cm
//     IHDR.fm
//     IHDR.im

//     IDAT.str = "IDAT"
// }

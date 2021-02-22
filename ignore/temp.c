#include<string.h>
#include <stdio.h>
#include "../png_ds.h"
// #include<conio.h>
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
int main()
{
    // char ch, fname[13]; FILE *fp;
    // // gets(fname);
    // scanf("%s", fname);
    // fp = fopen(fname,"rb");
    // for (int i = 0; i<1000; i++)
    // {
    //     ch = getc(fp);
    //     printf("%c", ch);
    // }    
    // fclose(fp);
    struct HEADER h1;
    h1.first_byte = 137;
    h1.PNG_SIGN[0] = 'P';
    h1.PNG_SIGN[1] = 'N';
    h1.PNG_SIGN[2] = 'G';
    h1.random1 = 3338;
    h1.random2 = 26;
    h1.random3 = 10;
    char *b= (char *)&h1;
    h1.crc= crc32b(b);
    
    //printf("%u\n",h1.crc);

    
}

#include "bmp_ds_new.h"
#include "png_ds.h"
// #include "Read_BMP.h"
#include"header.h"
#include<string.h>
#include"zlib.h"

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

// int writepng(struct HEADER,struct IHDR, struct IDAT); // Function to write the png data into a .png file

extern int writepng(struct HEADER h1,struct IHDR I1, struct IEND end)
{

  






   char arr[] = {0};
   char idat[] = "IDAT";
   int idatsize = reverse(img_info.header_size);
   FILE *f1 = fopen ("temp.bin", "wb");

   FILE *ft = fopen("convertedimage.png","wb");
   
   for(int i=(img_info.height-1);i>=0;i--)//writing the pixel data in IDAT chunk
   {
      //   image.graycolor[i] = (struct GRAYSCALE*) malloc(img_info.width*sizeof(struct GRAYSCALE));  
      //   fwrite(arr, 1, 1, f1);
        fwrite(image.graycolor[i],1,img_info.width,f1);     // sizeof(struct GRAYSCALE)    img_info.width       sizeof(image.graycolor[i])
   }-
   fclose(f1);

   FILE *f2 = fopen ("temp.bin", "rb");



   if (ft == NULL)
      return 1;
   
   fwrite(&h1,sizeof(struct HEADER),1,ft);//writing the header chunk
   printf("\n%li", sizeof(struct IHDR));
   fwrite(&I1,sizeof(struct IHDR),1,ft);//writing the IHDR chunk
   
   fwrite(&idatsize,sizeof(unsigned int),1,ft); //writing the IDAT chunk
   fwrite(&idat,4*sizeof(unsigned char),1,ft);
   
   
   def(f2, ft, 3);



 FILE *f = fopen("temp.bin", "rb");
    fseek(f, 0, SEEK_END);
    long int loc = ftell(f);
    fseek(f, 0, SEEK_SET);


   struct IDAT{
    
    unsigned int size;
    unsigned char str[4];//should be "IDAT"
   //  struct GRAYSCALE **graycolor;
    // unsigned char pixels;
    // struct GRAYSCALE arr[img_info.height][img_info.width];
    int arr[loc];
    unsigned char crc[4];
    };

   struct IDAT I2;

   printf("%li", loc);
   for(int i=0;i<(loc);i++)
   {
       fread(&I2.arr[i] ,1, 1, f);
   }
    
    



    I2.size = reverse(loc);     // (bmp_hdr.file_size - bmp_hdr.offset)
    // I2.str = "IDAT";
    strcpy(I2.str, "IDAT");
    char *d= (char *)&I2.str;
   //  I2.crc = crc32(0L, Z_NULL, 0);

   //  I2.crc= crc32(I2.crc, d, sizeof(d));
    I2.crc[0] = 0;
   I2.crc[1] = 0;
   I2.crc[2] = 0;
   I2.crc[3] = 0;

   
   // for(int i=(img_info.height-1);i>=0;i--)//writing the pixel data in IDAT chunk
   // {
   //    //   image.graycolor[i] = (struct GRAYSCALE*) malloc(img_info.width*sizeof(struct GRAYSCALE));  // COME ON GUYS ATLEAST WATCH THE VIDEO PROPERLY
   //      fwrite(arr, 1, 1, ft);
   //      fwrite(image.graycolor[i],1,img_info.width,ft);     // sizeof(struct GRAYSCALE)    img_info.width       sizeof(image.graycolor[i])
   // }
   fwrite(&I2.crc,4,1,ft);//writing the crc in IDAT chunk
   
   fwrite(&end.size,4,1,ft);
   fwrite(end.iend,4,1,ft);
   char array[4] = {0xae, 0x42, 0x60, 0x82};
   end.crc[0]=0xae;
	end.crc[1]=0x42;
	end.crc[2]=0x60;
	end.crc[3]=0x82;
   fwrite(array,4,1,ft);//writing the IEND chunk   
   // fwrite(,4*sizeof(char),1,ft);
   fclose(ft);

}

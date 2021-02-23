#include "bmp_ds_new.h"
#include "png_ds.h"
// #include "Read_BMP.h"
#include"header.h"



// int writepng(struct HEADER,struct IHDR, struct IDAT); // Function to write the png data into a .png file

extern int writepng(struct HEADER h1,struct IHDR I1,struct IDAT I2,struct IEND end)
{
   FILE *ft = fopen("convertedimage.png","wb");
   
   if (ft == NULL)
      return 1;
   
   fwrite(&h1,sizeof(struct HEADER),1,ft);//writing the header chunk
   printf("\n%li", sizeof(struct IHDR));
   fwrite(&I1,sizeof(struct IHDR),1,ft);//writing the IHDR chunk
   
   fwrite(&I2.size,sizeof(unsigned int),1,ft); //writing the IDAT chunk
   fwrite(&I2.str,4*sizeof(unsigned char),1,ft);
   
   for(int i=0/*img_info.height*7.0/8*/;i<(img_info.height);i++)//writing the pixel data in IDAT chunk
   {
      //   image.graycolor[i] = (struct GRAYSCALE*) malloc(img_info.width*sizeof(struct GRAYSCALE));  // COME ON GUYS ATLEAST WATCH THE VIDEO PROPERLY
        fwrite(image.graycolor[i],img_info.width,sizeof(struct GRAYSCALE),ft);
   }
   fwrite(&I2.crc,sizeof(unsigned int),1,ft);//writing the crc in IDAT chunk
   
   fwrite(&end,sizeof(struct IEND),1,ft);//writing the IEND chunk   
   // fwrite(,4*sizeof(char),1,ft);
   fclose(ft);

}

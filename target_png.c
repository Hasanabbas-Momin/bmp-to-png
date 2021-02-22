#include "bmp_ds_new.h"
#include "png_ds.h"
#include "Read_BMP.h"



void writepng(struct HEADER,struct IHDR, struct IDAT, int*); // Function to write the png data into a .png file

void writepng(struct HEADER h1,struct IHDR I1,struct IDAT I2,IEND)
{
   File *ft = fopen("convertedimage.png","wb");
   
   if (ft == NULL)
    return 1;
   
   fwrite(h1,sizeof(HEADER),1,ft);//writing the header chunk
   
   fwrite(I1,sizeof(struct IHDR),1,ft);//writing the IHDR chunk
   
   fwrite(&I2.size,sizeof(unsigned int),1,ft); //writing the IDAT chunk
   fwrite(&I2.str,4*sizeof(unsigned char),1,ft);
   
   for((i=(image.height-1));i>=0;i--)//writing the pixel data in IDAT chunk
   {
        image.graycolor[i] = (struct GRAYSCALE*) malloc(width*sizeof(struct GRAYSCALE));
        fwrite(image.graycolor[i],width,sizeof(struct GRAYSCALE),ft);
   }
   fwrite(&I2.crc,sizeof(unsigned int),1,ft);//writing the crc in IDAT chunk
   
   fwrite(IEND,4*sizeof(char),1,ft);//writing the IEND chunk   
   
   fclose(ft);

}
#include "bmp_ds_new.h"
#include "png_ds.h"
#include "Read_BMP.h"



void writepng(struct HEADER,struct IHDR, struct IDAT, int*);

void writepng(struct HEADER h1,struct IHDR I1,struct IDAT I2,IEND)
{
   File *ft = fopen("convertedimage.png","wb");
   if (ft == NULL)
    return 1;
   fwrite(h1,sizeof(HEADER),1,ft);
   fwrite(I1,sizeof(struct IHDR),1,ft);
   fwrite(I2,sizeof(struct(IDAT),1,ft);
   fwrite(IEND,4*sizeof(char),1,ft);   
   
}
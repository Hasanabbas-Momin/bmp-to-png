#include "bmp_ds_new.h"
#include "png_ds.h"
// #include "Read_BMP.h"
#include"header.h"



// int writepng(struct HEADER,struct IHDR, struct IDAT); // Function to write the png data into a .png file

extern int writepng(struct HEADER h1,struct IHDR I1, struct IEND end, int idatcrc)
{
   char idat[] = "IDAT";
   int idatsize = reverse(img_info.header_size);


   FILE *ft = fopen("convertedimage.png","wb");
   
   if (ft == NULL)
      return 1;
   
   fwrite(&h1,sizeof(struct HEADER),1,ft);//writing the header chunk
   printf("\n%li", sizeof(struct IHDR));
   fwrite(&I1,sizeof(struct IHDR),1,ft);//writing the IHDR chunk
   
   fwrite(&idatsize,sizeof(unsigned int),1,ft); //writing the IDAT chunk
   fwrite(&idat,4*sizeof(unsigned char),1,ft);
   
   for(int i=0;i<(img_info.height);i++)//writing the pixel data in IDAT chunk
   {
      //   image.graycolor[i] = (struct GRAYSCALE*) malloc(img_info.width*sizeof(struct GRAYSCALE));  // COME ON GUYS ATLEAST WATCH THE VIDEO PROPERLY
        fwrite(image.graycolor[i],1,img_info.width,ft);     // sizeof(struct GRAYSCALE)    img_info.width       sizeof(image.graycolor[i])
   }
   fwrite(&idatcrc,sizeof(unsigned int),1,ft);//writing the crc in IDAT chunk
   
   fwrite(&end,sizeof(struct IEND),1,ft);//writing the IEND chunk   
   // fwrite(,4*sizeof(char),1,ft);
   fclose(ft);

}

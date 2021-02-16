#include <stdio.h>
#include <stdlib.h>

struct BMPheader                        // struct a
{
    char file_type[2];
    unsigned int file_size;
    unsigned short int garbage1;
    unsigned short int garbage2;
    unsigned int offset;
};

struct Image_info                       // struct b
{
    unsigned int header_size;
    int width;
    int height;
    unsigned short int color_planes;
    unsigned short int bpp;             // bpp => bytes per pixel
    unsigned int compression;
    unsigned int image_size;
    int not_needed[4];
};

int main()
{
    FILE *fp = fopen("source_image.bmp","rb");   // *fp => file pointer
    
    struct BMPheader bmp_hdr;
    struct Image_info img_info;

    fread(bmp_hdr.file_type,2,1,fp);
    if((bmp_hdr.file_type[0] != 'B') || (bmp_hdr.file_type[1] != 'M'))
    {
        fclose(fp);
        return 0;
    }
    printf("File type:%c%c\n",bmp_hdr.file_type[0],bmp_hdr.file_type[1]);
    
    
    fread(&bmp_hdr.file_size,3*sizeof(int),1,fp);
    printf("File size:%d\n",bmp_hdr.file_size);

    
    fread(&img_info.header_size,sizeof(struct Image_info),1,fp);
    if((img_info.header_size != 40) || (img_info.bpp != 1) || (img_info.compression != 0 ))
    {
        fclose(fp);
        return 0;
    }
    
       
    printf("Header size: %u\nwidth: %d\nheight: %d\ncolorplanes: %hu\nBytes per pixel: %hu\nCompression: %u\nSize of image: %u",
            img_info.header_size,img_info.width,img_info.height,img_info.color_planes,img_info.bpp,img_info.compression,img_info.image_size);

    fseek(fp,bmp_hdr.offset,SEEK_SET);
    fclose(fp);
}
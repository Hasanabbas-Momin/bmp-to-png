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

struct GRAYSCALE
{
    unsigned char gray;
};

struct IMAGE
{
    int height;
    int width;
    struct GRAYSCALE **graycolor;
};

struct IMAGE readImage(FILE*fp,int height,int width)
{
    int i;

    struct IMAGE picture_data;
    picture_data.graycolor = (struct GRAYSCALE**) malloc(height*sizeof(void*));
    picture_data.height = height;
    picture_data.width = width;

    for((i=(picture_data.height-1));i>=0;i--)
    {
        picture_data.graycolor[i] = (struct GRAYSCALE*) malloc(width*sizeof(struct GRAYSCALE));
        fread(picture_data.graycolor[i],width,sizeof(struct GRAYSCALE),fp);
    }
    // printf()
    return picture_data;
}

void freeimagedata(struct IMAGE picture_data)
{
    int i;
    for(i=(picture_data.height-1);i>=0;i--) free(picture_data.graycolor[i]);
    free(picture_data.graycolor);
}

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

struct IMAGE Read_BMPfile(char *file)
{
    FILE *fp = fopen(file,"rb");   // *fp => file pointer
    
    struct BMPheader bmp_hdr;
    struct Image_info img_info;
    struct IMAGE image;

    fread(bmp_hdr.file_type,2,1,fp);
    if((bmp_hdr.file_type[0] != 'B') || (bmp_hdr.file_type[1] != 'M'))
    {
        fclose(fp);        
        perror("Input file format not supported .");
    }
    printf("File type:%c%c\n",bmp_hdr.file_type[0],bmp_hdr.file_type[1]);
    
    
    fread(&bmp_hdr.file_size,3*sizeof(int),1,fp);
    printf("File size:%d\n",bmp_hdr.file_size);

    
    fread(&img_info.header_size,sizeof(struct Image_info),1,fp);
    if((img_info.header_size != 40) || (img_info.bpp != 1) || (img_info.compression != 0 ))
    {
        fclose(fp);
        perror("Image not compatible .") ;
    }
    
       
    printf("Header size: %u\nwidth: %d\nheight: %d\ncolorplanes: %hu\nBytes per pixel: %hu\nCompression: %u\nSize of image: %u",
            img_info.header_size,img_info.width,img_info.height,img_info.color_planes,img_info.bpp,img_info.compression,img_info.image_size);

    fseek(fp,bmp_hdr.offset,SEEK_SET);
    image = readImage(fp,img_info.height,img_info.width);

    // for(int i=0;i<(img_info.height);i++)
    // {
    //     for(int j=0;j<(img_info.width);j++)
    //     {
    //         printf("%c",image.graycolor[i][j]);
    //     }
        
    // }





    fclose(fp);
    // freeimagedata(image);
    


    return image;
}

// int main(int argc, char *argv[])
// {
//     struct IMAGE input_file = Read_BMPfile(argv[1]);
// }
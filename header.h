#ifndef header_h
#define header_h
#pragma pack(1)
#include<stdio.h>
#include<stdlib.h>

int unsigned reverse(int variable);
struct GRAYSCALE                                        // struct to store information of a single pixel 
{
    unsigned char gray;
};
struct IMAGE                                            // struct to be used to get the pixel data
{
    int height;
    int width;
    struct GRAYSCALE **graycolor;
};
struct IMAGE readImage(FILE*fp,int height,int width);
struct BMPheader bmp_hdr;
struct Image_info img_info;
struct IMAGE image;
void freeimagedata(struct IMAGE picture_data);
struct IMAGE Read_BMPfile(char *file);

int def(FILE *source, FILE *dest, int level);
// void BMP_TO_PNG()
// struct HEADER h1;
// struct IHDR I1;
// struct IDAT I2;

extern int writepng(struct HEADER h1,struct IHDR I1, struct IEND end);

void freeimagedata(struct IMAGE picture_data);
#endif
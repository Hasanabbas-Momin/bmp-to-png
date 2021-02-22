// #include "bmp_ds_new.h"
#include "png_ds.h"
#include "Read_BMP.h"
#include<string.h>
void BMP_TO_PNG()
{
    struct HEADER h1;
    h1.first_byte = 137;
    // h1.PNG_SIGN[3] = "PNG";
    strcpy(h1.PNG_SIGN, "PNG");
    h1.random1 = 3338;
    h1.random2 = 26;
    h1.random3 = 10;
    
    
    struct IHDR I1;
    // I1.size = Read_BMPfile.bmp.hdr.file_size;     // this is equal to 13 so no need to take it
    I1.size = 13;
    // I1.str = "IHDR";
    strcpy(I1.str, "IHDR");
    I1.width = img_info.width;
    I1.height = img_info.height;
    I1.bit_depth = 8;
    I1.colour_type = 0;
    I1.cm = 0;
    I1.fm = 0;
    I1.im = 0;

    struct IDAT I2;
    I2.size = img_info.header_size;
    // I2.str = "IDAT";
    strcpy(I2.str, "IDAT");

    // IEND[] = {"I", "E", "N", "D"};
    strcpy(IEND, "IEND");
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

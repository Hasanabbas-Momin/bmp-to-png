




struct a
{
    char file_type[2];//has to be BM or 42 4D 
    unsigned int file_size;
    unsigned short int garbage1,garbage2;//reserved ones
    int offset;//PixelDataOffset

// FileType	2 bytes	A 2 character string value in ASCII to specify a DIB file type. It must be 'BM' or '0x42 0x4D' in hexadecimals for modern compatibility reasons.
// FileSize	4 bytes	An integer (unsigned) representing entire file size in bytes. This value is basically the number of bytes in a BMP image file.
// Reserved	2 bytes	These 2 bytes are reserved to be utilized by an image processing application to add additional meaningful information. It should be initialized to '0' integer (unsigned) value.
// Reserved	2 bytes	Same as the above.
// PixelDataOffset	4 bytes	An integer (unsigned) representing the offset of actual pixel data in bytes. In nutshell:- it is the number of bytes between start of the file (0) and the first byte of the pixel data.


    
    
};
typedef struct a BMPHEADER;

struct b
{
    unsigned int header_size;
    int width;
    int height;
    unsigned short int color_planes;
    unsigned short int bpp;//bits per pixel for us it is 8(grayscale)
    unsigned int compression;
    unsigned int image_size;
    // int not_needed[4];//XpixelsPerMeter,YpixelsPerMeter,TotalColors,ImportantColors

//     Field Name, Size in bytes, Description
// HeaderSize, 4 bytes, An integer (unsigned) representing the size of the header in bytes. It should be '40' in decimal to represent BITMAPINFOHEADER header type.
// ImageWidth,	4 bytes, An integer (signed) representing the width of the final image in pixels.
// ImageHeight, 4 bytes, An integer (signed) representing the height of the final image in pixels.
// Planes,	2 bytes, An integer (unsigned) representing the number of color planes of the target device. Should be '1' in decimal.
// BitsPerPixel, 2 bytes, An integer (unsigned) representing the number of bits (memory) a pixel takes (in pixel data) to represent a color.
// Compression, 4 bytes, An integer (unsigned) representing the value of compression to use. Should be '0' in decimal to represent no-compression (identified by 'BI_RGB').
// ImageSize, 4 bytes, An integer (unsigned) representing the final size of the compressed image. Should be '0' in decimal when no compression algorithm is used.
// XpixelsPerMeter, 4 bytes, An integer (signed) representing the horizontal resolution of the target device. This parameter will be adjusted by the image processing application but should be set to '0' in decimal to indicate no preference.
// YpixelsPerMeter, 4 bytes, An integer (signed) representing the verical resolution of the target device (same as the above).
// TotalColors, 4 bytes, An integer (unsigned) representing the number of colors in the color pallet (size of the color pallet or color table). If this is set to '0' in decimal :- 2^BitsPerPixel colors are used.
// ImportantColors, 4 bytes, An integer (unsigned) representing the number of important colors. Generally ignored by setting '0' decimal value.
// ----,----,----
// Total, 40 bytes, Size of the BITMAPINFOHEADER in bytes.





};

typedef struct b IMAGEINFO;

struct c//actual final img is stored here
{
    BMPHEADER b_head;
    IMAGEINFO b_img_info;
    unsigned char *pixels;//8 bits is 1 byte which is sizeof(char). Need 0-255 which is unsigned char

};

typedef struct c BMP;





#ifndef pngds_h
#define pngds_h

struct HEADER{

    char first_byte;//should be 89 in hex
    char PNG_SIGN[3];//"PNG"
    short random1;//A DOS-style line ending (CRLF) to detect DOS-Unix line ending conversion of the data.
    char random2;//A byte that stops display of the file under DOS when the command type has been used—the end-of-file character.
    char random3;//A Unix-style line ending (LF) to detect Unix-DOS line ending conversion.
    unsigned int crc;

   // (decimal)              137  80  78  71  13  10  26  10
   // (hexadecimal)           89  50  4e  47  0d  0a  1a  0a
   // (ASCII C notation)    \211   P   N   G  \r  \n \032 \n
};


struct IHDR{
    
    unsigned int size;//length of data in file
    char str[4];//should be "IHDR"
    int width;
    int height;
    //chars are of 1 byte
    char bit_depth;// 8 for us. 256 shades of gray  :)
    char colour_type;// 0 for us
    char cm;//compression method
    char fm;//filter method
    char im;//interlace method
    unsigned int crc;
    // Width	4 bytes
    // Height	4 bytes
    // Bit depth	1 byte
    // Colour type	1 byte    
    // Compression method	1 byte
    // Filter method	1 byte
    // Interlace method	1 byte

};


//No PLTE chunk for us as it is grayscale(colour_type=0)


struct IDAT{
    
    unsigned int size;
    char str[4];//should be "IDAT"
    unsigned char pixels;
    unsigned int crc;
    
};


struct TRNS{//ancillary chunk
    
    unsigned int size;
    char str[4];//should be "tRNS" or 116 82 78 83
    short transparency;
    unsigned int crc;

    
    //  For colour types 0 or 2, two bytes per sample
    //  are used regardless of the image bit depth . 
    //  Pixels of the specified grey sample value or RGB sample values are treated as 
    //  transparent (equivalent to alpha value 0); all other pixels are to be treated 
    //  as fully opaque (alpha value 2bitdepth-1). If the image bit depth is less than 
    //  16, the least significant bits are used and the others are 0.
};

struct BKGD{//ancillary chunk
    
    unsigned int size;
    char str[4];//"bKGD" or 98 75 71 68
    unsigned short bg;//0-255
    unsigned int crc;
    // For colour types 0 and 4 (greyscale, greyscale with alpha), the value
    //  is the grey level to be used as background in the range 0 to (2bitdepth)-1
};

char IEND[4];//should be "IEND"

//no sBIT as sample_depth=bit_depth=8
//fyi on sbit:https://stackoverflow.com/questions/9503994/whats-the-purpose-of-the-sbit-chunk-in-the-png-file

//I have skipped all other ancillary chunks as they are mainly for coloured images



struct HEADER h1;
struct IHDR I1;
struct IDAT I2;


#endif
#include "png_ds.h"
#include"bmp_ds_new.h"
#include "header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>



extern unsigned int reverse(int variable)
{
    // int variable = 0x12345678; /* 4 byte integer containing some value */
    char byte[4]; /* Variables to hold the char-values */

    // /* extract the bytes as characters */
    // byte[0] = (char)((variable >> (0*8)) & 0x000000FF);
    // byte[1] = (char)((variable >> (1*8)) & 0x000000FF);
    // byte[2] = (char)((variable >> (2*8)) & 0x000000FF);
    // byte[3] = (char)((variable >> (3*8)) & 0x000000FF);

    /* Another way using pointers */
    byte[3] = ((char*)(&variable))[0];
    byte[2] = ((char*)(&variable))[1];
    byte[1] = ((char*)(&variable))[2];
    byte[0] = ((char*)(&variable))[3];
    return *((unsigned int*)byte);
}
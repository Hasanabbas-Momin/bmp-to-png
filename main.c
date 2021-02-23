#include "png_ds.h"
#include"bmp_ds_new.h"
#include "header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Read_BMP.h"
void BMP_TO_PNG();

int main(){
    char s[20];
    scanf("%s", s);
    Read_BMPfile(s);
    BMP_TO_PNG();
    writepng(h1, I1, I2, end);
}
CC=gcc
CFLAGS=-I.

make_img: main.o bmp-to-png.o Read_BMP.o reverse.o target_png.o
	$(CC) -o make_img main.o bmp-to-png.o Read_BMP.o reverse.o target_png.o

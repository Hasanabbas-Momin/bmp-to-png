#include<string.h>
#include <stdio.h>
// #include<conio.h>
int main()
{
    char ch, fname[13]; FILE *fp;
    // gets(fname);
    scanf("%s", fname);
    fp = fopen(fname,"rb");
    for (int i = 0; i<150; i++)
    {
        ch = getc(fp);
        printf("%c", ch);
    }    
    fclose(fp);
}

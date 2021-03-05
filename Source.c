#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
float BMI(float weight, float height)
{
    return (weight / height * 2);
 }

int main()
{
    FILE* fp;
    int i;
    char fn[50];
    char str[50];
    fp = fopen("persoane.txt", "w+");
    printf("Introdu numele persoanei: ");
    scanf("%s", str);
    for (i = 0; str[i] != '\n'; i++) {
        fputc(str[i], fp);
    }
    fclose(fp);
    





   
    return 0;
}
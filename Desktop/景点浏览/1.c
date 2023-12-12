#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
   int text[3][3]={0};
    FILE *file;
    file=fopen("/Users/nifangqin/Desktop/景点浏览/1.txt","r");
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    fscanf(file,"%d",&text[i][j]);
    for(int i=0; i<3; i++) 
    for(int j=0; j<3; j++)
{printf("%d ",text[i][j]);
if(j==2) printf("\n");}
}
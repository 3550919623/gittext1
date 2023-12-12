#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define maxnum 10//定义有十个景点
#define INFINITY 65535//定义无穷大
typedef struct{
char name;
char codename[10];
char information[10];
}attraction;//定义景点结构体
typedef struct{
    attraction attractions[maxnum];
}attractionsset;//将maxnum个景点凑成一个结构体
typedef struct{
    int vextex[maxnum];//储存顶点数据
    int pathlength[maxnum][maxnum];//储蓄两点之间距离；
}mgraph;//定义图
typedef int shortpath[maxnum][maxnum];
typedef int pathmatrix[maxnum][maxnum]; 
void readinmofation(attractionsset *set);//读取景点信息
void searchinfomation(attractionsset set,char name);//查找景点信息
void windowsprint1();//景点信息查询窗口
void windowsprint2();//最短路径查询窗口
void readpathlength(mgraph *map);//读取路径长度
int locate(attractionsset set,char name);//定位景点在数组中的位置
void calculate(mgraph map,pathmatrix *p,shortpath *sp);//计算最短路径
void printpath(pathmatrix p,attractionsset set,int s1,int s2);//打印出路径走法
void window();
int module=-1;//定义模式
int module1=1;//模式一状态
int module2=1;//模式二状态
attractionsset set;//定义景点集合
mgraph map;//定义地图
shortpath sp;//定义最短路径数组
pathmatrix p;//定义经过景点路径顺序数组
int main()
{
readinmofation(&set);
readpathlength(&map);
calculate(map,&p,&sp);
window();

}
void windowsprint1()//景点信息查询窗口
{
    printf("景点信息查询窗口\n");
    printf("A 景点1\n");
    printf("B 景点2\n");
    printf("C 景点3\n");
    printf("D 景点4\n");
    printf("E 景点5\n");
    printf("F 景点6\n");
    printf("G 景点7\n");
    printf("H 景点8\n");
    printf("I 景点9\n");
    printf("J 景点10\n");
    printf("请输入想要找到的景点编号:\n");
}
void windowsprint2()//最短路径查询窗口
{
    printf("最短路径查询窗口\n");
    printf("A 景点1\n");
    printf("B 景点2\n");
    printf("C 景点3\n");
    printf("D 景点4\n");
    printf("E 景点5\n");
    printf("F 景点6\n");
    printf("G 景点7\n");
    printf("H 景点8\n");
    printf("I 景点9\n");
    printf("J 景点10\n");
    printf("请输入起点和终点:\n");
}
void readinmofation(attractionsset *set)//读取景点信息
{
FILE *fread1 = fopen("/Users/nifangqin/Desktop/景点浏览/name.txt","r");
FILE *fread2 = fopen("/Users/nifangqin/Desktop/景点浏览/codename.txt","r");
FILE *fread3 = fopen("/Users/nifangqin/Desktop/景点浏览/information.txt","r");
for(int i=0;i<maxnum;i++){fscanf(fread1,"%c",&set->attractions[i].name);
fscanf(fread2,"%s",&set->attractions[i].codename);
fscanf(fread3,"%s",&set->attractions[i].information);
}
fclose(fread1);fclose(fread2);fclose(fread3);
}
void searchinfomation(attractionsset set,char name)//查找景点信息
{
for(int i=0;i<10;i++) 
if(name==set.attractions[i].name) printf("%c %s %s\n",set.attractions[i].name,set.attractions[i].codename,set.attractions[i].information);
}
void readpathlength(mgraph *map)
{
    FILE *fread;
    fread = fopen("/Users/nifangqin/Desktop/景点浏览/pathlength.txt","r");
    for(int i=0;i<maxnum;i++)
    for(int j=0;j<maxnum;j++)
    fscanf(fread,"%d",&map->pathlength[i][j]);
    fclose(fread);
}
int locate(attractionsset set,char name)//定位景点在数组中的位置
{
int result=-1;
for(int i=0;i<maxnum;i++){
if(name==set.attractions[i].name) {result=i;break;}
}
return result;
}
void calculate(mgraph map,pathmatrix *p,shortpath *sp)//计算最短路径
{
for(int x=0;x<maxnum;x++){
for(int y=0;y<maxnum;y++){
(*sp)[x][y]=map.pathlength[x][y];
(*p)[x][y]=-1;
}
}
for(int k=0;k<maxnum;k++){
for(int x=0;x<maxnum;x++){
for(int y=0;y<maxnum;y++){
if((*sp)[x][y]>(*sp)[x][k]+(*sp)[k][y]){
(*sp)[x][y]=(*sp)[x][k]+(*sp)[k][y];
(*p)[x][y]=k;
}
}
}
}
}
void printpath(pathmatrix p,attractionsset set,int s1,int s2)//打印出路径走法
{
int temp;
int count=0;
char spotset[10]={'\0'};
temp=p[s1][s2];
printf("%c",set.attractions[s1].name);
while(temp!=-1)
{
spotset[count]=set.attractions[temp].name;
temp=p[s1][temp];
count++;
}
for(int i=count-1;i>=0;i--) 
cout<<"---"<<spotset[i];
printf("--%c",set.attractions[s2].name);
}
void window()//总进程
{
printf("请输入模式（1查找信息 2寻找最短路径 其余退出）：");
cin>>module;
if(module==1){//选择1模式
while(module1){
system("clear");//清屏
windowsprint1();
char name;
cin>>name;
if(name>'J'||name<'A') {printf("输入信息有误"); return;}
system("clear");//清屏
searchinfomation(set, name);
printf("按1继续查找，按0退出系统：");
cin>>module1;
}
if (module1==0) {system("clear");//清屏;
window();}
}
else if(module==2){//选择模式二
while(module2){
system("clear");//清屏
windowsprint2();
char name1;
char name2;
cin>>name1>>name2;
int s1=locate(set,name1);
int s2=locate(set,name2);
printf("最短的路径与走法：\n");
printf("%d\n",sp[s1][s2]);
printf("最短路径为：");
printpath(p,set,s1,s2);
printf("按1继续查找，按0退出系统：");
cin>>module2;
}
if (module2==0) {system("clear");//清屏;
window();}
}
else printf("谢谢使用");
}
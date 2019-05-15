#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
 FILE *fin;
 int i,cols,rows,*count;
 char val;
 if(argc!=2)
 {
  return 1; 
 }
 fin = fopen(argv[1],"r");

//finding the number of cols
 cols=0;
 fscanf(fin,"%c",&val);
 while(1)
 {
  if(val=='\n')
  break;
  if(val!=' ')
  cols++;
  fscanf(fin,"%c",&val);
 }
 printf("\nNumber of columns = %d\n",cols);
 fclose(fin);
 fin = fopen(argv[1],"r");
 //Generation of 1 item frequent items

 count = (int*)malloc(sizeof(int)*cols);

 for(i=0;i<cols;i++)
 {
  count[i] =0;
 }

 while(!feof(fin))
 {
  for(i=0;i<cols;i++)
  {
   fscanf(fin,"%c",&val);
   if(val=='1')
   count[i]++;
   fscanf(fin,"%c",&val);
  }
 }
 //Generation of 1-item frequent sets completed!!

 printf("\n1-item frequent item sets..\n");
 for(i=0;i<cols;i++)
 {
  printf("\n%d -> %d",i+1,count[i]);
 }
 fclose(fin);
 return 0;
}

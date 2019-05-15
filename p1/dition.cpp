#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void check(char str[20]);
void display(int ind[10]);

int main ()
{
char string[20],c;
for(int i=0;i<20;i++)
{
string[i]='\0'	;
}

cout<<"enter word..";
c='c';
while(c!='*'){
int i=0;	
//cout<<"lop"<<endl;
cout<<endl;
cout<<string;
cin>>c;
while(string[i]!='\0')
{
//cout<<"inner lop"<<endl;
i++;	
}
//condition for alphabet  done
if(c<=122 && c>=97 || c>=65 && c<=90)
{

string[i]=c;
check(string);
i++;	
}else{
	if(c!='*')
	cout<<"please enter proper char";
i--;
}

}
//cout<<string;

return 0;	
}
void check(char str[20])
{
	char string[20];
	int n=0;
		FILE *fp;
		fp=fopen("dic2.txt","r");
		//calculate no of lines done
			while(!feof(fp)){
				fgets(string,30,fp);
			n++;
			}
		//	cout<<" n is  "<<n<<endl;
           
		rewind(fp);
		int i=0;
		 float weight[n];
            float wt;
            float sn;
            for(int j=0;j<n;j++)
            {
            	weight[j]=0;	
            }
	while(!feof(fp)){
		
fgets(string,30,fp);
sn=strlen(string)-1;
wt=1/sn;
int l;
int flag=0;
//cout<<wt<<endl;
for(int j=0;j<strlen(str);j++)
{//for each word check
flag=0;
for(int k=0;k<strlen(string);k++){
//each word of string 
if(str[j]==string[k]){
	//	cout<<" flag is 1 "<<str[j]<<string<< wt<<endl;
	string[k]='*';
	weight[i]=weight[i]+wt;
	//cout<<string<<"weight is "<<weight[i]<<" i is "<< i<<endl;
flag=1;
break;	
}	
}


l=j;
}
if(flag==0){
//	cout<<" flag is o   "<<str[l]<<"    "<<string<<endl;/// negative stuff NEEDED OR NOT..???
weight[i]=weight[i]-0.17;	
}
	
//cout<<"weight is "<<weight[l]<<endl;	
i++;
		}		
	fclose(fp);
	int index[n];
	for(int j=0;j<n;j++)
            {
            	index[j]=j;	
            }
            
            //sorting
            int temp;
            for(i=0;i<n;i++)
            {
            	for(int j=0;j<i;j++)
            	{
            		if(weight[j]<weight[i])
            		{
            		temp=weight[j];
					weight[j]=weight[i];
					weight[i]=temp;	
					
					temp=index[j];
					index[j]=index[i];
					index[i]=temp;				
					
            		}
            	}
            }
            
		 for(int j=0;j<n;j++)
            {
            //	cout<<"line no "<<index[j]+1<<"     "<<weight[j]<<endl;	
            }
            int ind[10];
            for(int j=0;j<10;j++)
            {
            	ind[j]=index[j];	
            }
            display(ind);
	
}
void display(int ind[10])
{
FILE *fp;
char string[20];
		fp=fopen("dic2.txt","r");
	for(int i=0;i<10;i++){
		rewind(fp);
		for(int j=0;j<ind[i];j++)
		{
			fgets(string,30,fp);	
		}
		fgets(string,30,fp);
		cout<<"				"<<string;
	}
}


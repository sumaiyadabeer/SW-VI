#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstring>
#include <vector>
#include <cstdlib>
using namespace std;
int N=1;
int no;
vector<int>fstate;
	string op[10][10];
		string op1[10][10];
 void  remove(int k);
 int retrn(char c)
{
		if(c=='0')
	return 0;
	if(c=='1')
	return 1;
		if(c=='2')
	return 2;
		if(c=='3')
	return 3;
		if(c=='4')
	return 4;
		if(c=='5')
	return 5;
		if(c=='6')
	return 6;
		if(c=='7')
	return 7;
		if(c=='8')
	return 8;
		if(c=='9')
	return 9;
		
}
int main()
{
	
       FILE *fp,*fpo;
       char str[30],fstr[30];
  fp=fopen("input.txt","r");
  
  fgets(str,30,fp);
 
  int I;
  fgets(str,30,fp);
  for(int i=0;i<strlen(str);i++){//no of state
						if(str[i]==',')
						N++;
}
	//string op[N][N];
	//	string op1[N][N];
   fgets(str,30,fp);//no of alphabet
   I= retrn(str[2]);
  cout<<I<<N<<endl;
 fgets(fstr,30,fp);//final states;
 for(int i=4;i<strlen(str);i+=3){
 //	cout<<;
 fstate.push_back(retrn(str[i]));
 }						
  for(int i=0;i<N;i++)
  {
  	for(int j=0;j<N;j++){
  		op[i][j].clear();	
  	}
  
  }
  int fr,to;
  while(!feof(fp)){
			fgets(str,30,fp);
			 fr=retrn(str[3]);
			 to=retrn(str[9]);
				op[fr][to]=str[5];	
				//cout<<retrn(str[3])<<retrn(str[9])<<str[5]<<endl;
				}
  
 

  fclose(fp);
    //cout<<op[1][1]+""+op[1][1]<<"..."<<endl;
     if(op[1][1].empty())
     cout<<"oh yes"<<endl;

   for(int i=0;i<N;i++)
  {
  	for(int j=0;j<N;j++){
  	cout<<i<<j<<"    "<<op[i][j]<<endl;	
  	}
  cout<<endl;
  }
    for(int i = 0;i<N;i++){
    	cout<<"going to rmv state"<<i<<endl;
       remove(i);
	     for(int i=0;i<N;i++)
  {
  	for(int j=0;j<N;j++){
  	op[i][j]=op1[i][j];	
  	}
  
  }
    }
    
fpo=fopen("output.txt","w");
if(fpo==NULL)
printf("file not open");
fprintf(fpo,"                REGULAR EXPRESSION IS:           \n");
I=0;
int F=1;

     for(int i=4;i<strlen(fstr);i+=3)
     {
     	if(i!=4 && !op[I][F].empty() && i<strlen(fstr))
     	fprintf(fpo,"+");
     F=retrn(fstr[i]);
    for(int i=0;op[I][F][i]!='\0';i++)
fprintf(fpo,"%c",op[I][F][i]);


     }
    	  
    
  
        




cout<<op[0][1];
fclose(fpo);


    getch();
    return 0;
}
    
  void  remove(int k){
  	cout<<"supplied k is"<<k<<endl;
  	string temp;
  for(int i = 0;i<N;i++) {
 
    for (int j = 0 ;j<N;j++){
    	cout<<" i AND j is "<<i<<" "<<j<<endl;
    	getch();
 
    if(!op[k][k].empty()&&!op[i][k].empty()&&!op[k][j].empty())
    {
    	temp=op[i][k] +'*'+op[k][k]+op[k][j];
    }else
    {
    	temp.clear();
    }
	  if(!op[i][j].empty()&&!op[k][k].empty()&&!op[i][k].empty()&&!op[k][j].empty())
	{
		op1[i][j]= op[i][j] + '+' +temp ;

	}   else if(!op[i][j].empty()){
       	op1[i][j]= op[i][j];
       }else if (!op[k][k].empty()&&!op[i][k].empty()&&!op[k][j].empty()){
       	op1[i][j]=temp;
       }else{
       	
       }
  }
   
  
 }
// no--;
  for(int i=0;i<N;i++)
  {
  	for(int j=0;j<N;j++){
  	cout<<i<<j<<"    "<<op1[i][j]<<endl;	
  	}
  cout<<endl;
  }

 }
      

      
      
   

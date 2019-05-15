#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstring>

using namespace std;
int n=3;
int no;
	string op[3][3];
		string op1[3][3];
 void  remove(int k);
class mat {
	public:
	string L;
};

int main()
{
	

  
  for(int i=0;i<3;i++)
  {
  	for(int j=0;j<3;j++){
  		op[i][j].clear();	
  	}
  
  }
 op[0][0]="1";
 op[0][1]="0";
 op[1][2]="1";
 op[2][1]="1";
 op[2][2]="0";
  
    cout<<op[1][1]+""+op[1][1]<<"..."<<endl;
     if(op[1][1].empty())
     cout<<"oh yes"<<endl;
  no=n;
   for(int i=0;i<3;i++)
  {
  	for(int j=0;j<3;j++){
  	cout<<i+1<<j+1<<"    "<<op[i][j]<<endl;	
  	}
  cout<<endl;
  }
    for(int i = 0;i<3;i++){
    	cout<<"going to rmv state"<<i<<endl;
       remove(i);
	     for(int i=0;i<3;i++)
  {
  	for(int j=0;j<3;j++){
  	op[i][j]=op1[i][j];	
  	}
  
  }
    }
    getch();
    return 0;
}
    
  void  remove(int k){
  	cout<<"supplied k is"<<k<<endl;
  	string temp;
  for(int i = 0;i<3;i++) {
    for (int j = 0 ;j<3;j++){
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
 no--;
  for(int i=0;i<3;i++)
  {
  	for(int j=0;j<3;j++){
  	cout<<i+1<<j+1<<"    "<<op1[i][j]<<endl;	
  	}
  cout<<endl;
  }

 }
      
      
      
      
   

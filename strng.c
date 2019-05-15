#include <iostream> 
#include <stdio.h> 
//#include <conio.h>
 #include <cstring>
  #include <ctype.h> 
 // #include <cprocess>
 
 using namespace std;
int main() {
int k,j;
char state = '0' ;
char ch = '\0';
char token[20]={'\0'};
char stt[3][2]= {'\0', '2' ,
'0' , '1' ,
'1' , '1' }; cout<< "Input integer value : " ;
 cin>>token;
for( int i=0; token[i] != '\0'; i++) {
if (isdigit(token[i])) { ch= '2' ; }
else
{ printf( "Invalide value" ); //getchar(); 
cout<<"going to out";
 }
for ( j=1; j<3 && ch != stt[0][j]; j++);
for (  k=1; k<2 && state != stt[k][0]; k++); state=stt[k][j];
} printf( "Valide value" );
// getchar();
return 0; }

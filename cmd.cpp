/*#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main ()
{
   char command[50];

   strcpy( command, "ls -l" );
   system(command);
exec("command > file_output.txt");
   return(0);
} 
/*#include <stdio.h>
#include <stdlib.h>
int main() {
   char output[1000];
   output= system( "ls -l" );
   printf( "%s", output);
   return 0;
}*/
#include<iostream>
#include <cstring>
//#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(void)
{
char command[50];
string i;

cout<<"enter regular ex"<<endl;
cin>>i;

char c=i[0];
int len=i.length();

while(len!=0){
//dec l according to yrself
//lop





}






string s="grep  \"^a\\|^b\" strings.txt > mylsout.txt";

for(int j=0;j<s.length();j++){
command[j]=s[j];

}
//strcpy(command,s );
 system(command);
 
 /* read from the file and store in a variable for processing by the program logic*/
}

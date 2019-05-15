/*
g++ -std=c++11 newre.cpp

Symbol  Meaning
c       Match the literal character c once, unless it is one of the special characters.
^        Match the beginning of a line.
.        Match any character that isn't a newline.
$        Match the end of a line.
|           Logical OR between expressions.
()       Group subexpressions.
[]       Define a character class.
*       Match the preceding expression zero or more times.
+       Match the preceding expression one ore more times.
?       Match the preceding expression zero or one time.
{n}    Match the preceding expression n times.
{n,}     Match the preceding expression at least n times.
{n, m}  Match the preceding expression at least n times and at most m times.
\d      Match a digit.
\D      Match a character that is not a digit.
\w     Match an alpha character, including the underscore.
\W      Match a character that is not an alpha character.
\s      Match a whitespace character (any of \t, \n, \r, or \f).
\S      Match a non-whitespace character.
\t      Tab.
\n     Newline.
\r     Carriage return.
\f     Form feed.
\m      Escape m, where m is one of the metacharacters described above: ^, ., $, |, (), [], *, +, ?, \, or /.





*/

#include <iostream>
#include <string>
#include <regex>
#include <cstring>
#include <stack>
using namespace std;
int main ()
{
char text[50];
FILE *ptr;
ptr=fopen("strings.txt","r")  ;
if(!ptr){
  cout<<"File cannot be opened.";
  }  
stack<string> mystrings;
int count=0;
char word[50];
fgets(text,50,ptr); 
int i;
while(text[0]!=42){
for (i=0;i<strlen(text)-1;i++){
  word[i]=text[i];
  }
word[i]='\0';
cout<<word<<endl;
cout<<strlen(word)<<endl;
mystrings.push(word);
fgets(text,50,ptr);
count++;
}

string str;
string e;
cout<< "ENTER A REGULAR EXPRESSION: ";
cin>>e;
std::regex re(e);
for (int i=0;i<count;i++){
    str=mystrings.top();
    mystrings.pop();
    std::string s(str);
if (std::regex_match (s,re))
  std::cout<<str<<endl;
  }
return 0;
}
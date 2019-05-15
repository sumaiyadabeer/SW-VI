//g++ -std=c++11 p8.cpp
#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main ()
{

  string kkk;
  string kk;
  cout<<"enter the regular expression";
  //printf("enter the regular expression");
  cin>>kk;
  //regex e1 ("(0|1)*101(0|1)*");
  regex e1 (kk);
  cout<<"enter the strings to check";
  for(int i=0;i<4;i++)
  {
  cin>>kkk;
  if (regex_match (kkk,e1))
  cout << "string 1 matched\n";
  }
  
  return 0;
}

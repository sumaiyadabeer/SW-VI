
#include <stdio.h>
#include <stdbool.h>
 

bool mat(char *o, char *t)
{
   int k;
   
     if (*o == '\0' && *t == '\0')
       k=0;
     if (*o == '*' && *(o+1) != '\0' && *t == '\0')
       k=1;
     if (*o == '?' || *o == *t)
       k=2;
     if (*o == '*')
       k=3;


switch(k)
{
case 0:
    return true;
break;
case 1:
  return false;
break;
case 2:
return mat(o+1, t+1);
break;
case 3:
 return mat(o+1, t) || mat(o, t+1);
break;
default:
return false;

}

/*
    // If we reach at the end of both strings, we are done
    if (*first == '\0' && *second == '\0')
        return true;
 
    // Make sure that the characters after '*' are present
    // in second string. This function assumes that the first
    // string will not contain two consecutive '*'
    if (*first == '*' && *(first+1) != '\0' && *second == '\0')
        return false;
 
    // If the first string contains '?', or current characters
    // of both strings match
    if (*first == '?' || *first == *second)
        return match(first+1, second+1);
 
    // If there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if (*first == '*')
        return match(first+1, second) || match(first, second+1);
    return false;*/
}
 

 

int main()
{

char in [20],in2 [30];

printf("enter regular expression\n\n\t\t");
scanf("%s",in);


printf("enter strng\n\n\t\t");
scanf("%s",in2);


if(mat(in, in2)){
puts("Yes");
}
else
puts("No");

    return 0;
}

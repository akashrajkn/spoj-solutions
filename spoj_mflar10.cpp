/*
  problem code: MFLAR10
  problem number: 7757
  problem link: http://www.spoj.com/problems/MFLAR10/
*/

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <utility>
#include <climits>
#include <ctime>

using namespace std;

int main()
{
  char s[1100];
  
  while(1)
  {
    gets(s);
    
    if(strlen(s)<=0)
    {
      continue;
    }
    if(strlen(s)==1 && s[0]=='*')
    {
      return 0;
    }
    
    int len = strlen(s);
    char first = s[0];
    int j=0;

    while(first==' ')
    {
      first = s[j];
      j++;
    }

    char cFirst;

    if(first>=97 && first<=132)
    {
      cFirst = first - 'a' + 'A';
    }
    else
    {
      cFirst = first -'A' + 'a';
    }

    char res = 'Y';

    for(int i=j+1; i<len; i++)
    {
      if(s[i-1]==' ' && s[i]!=' ')
      {
        if(s[i]!=first && s[i]!=cFirst)
        {
          res = 'N';
          break;
        }
      }
    }

    printf("%c\n", res);
  }

  return 0;
}
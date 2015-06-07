/*
problem code: The Next Palindrome
problem number: 5
problem link: http://www.spoj.com/problems/PALIN/
*/

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<iterator>
#include<set>
#include<map>
#include<iostream>
#include<sstream>
#include<deque>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<utility>
#include<climits>
#include<list>
#include<bitset>
#include<fstream>

using namespace std;

#define OfTheKing 0
#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define MP make_pair
#define all(c) c.begin(),c.end()
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PB push_back
#define PF push_front
//#define g_u getchar_unlocked() //if windows use getchar()
//#define p_u(x) putchar_unlocked(x) //if windows use putchar()
#define p_u(x) putchar(x) 
#define g_u getchar()

typedef pair<long long, long long> pii;
typedef long long ll;


//fast input function
inline void getInt(ll &n)
{
  n = 0;
  ll ch = g_u;
  ll sign = 1;
  while (ch < '0' || ch > '9')
  {
    if (ch == '-')
    {
      sign = -1;
    }
    ch = g_u;
  }
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';
    ch = g_u;
  }
  n *= sign;
}


int greater(vector<int>&, vector<int>&, int);


int main()
{
  ll t, length;
  char s;
  vector<int> inpNum(1000000), newNum(1000000);

  getInt(t);

  while (t--)
  {
    length = 0;
    while (1)
    {
      s = g_u;

      if ( s<'0' || s>'9' )
      {
        break;
      }
      inpNum[length] = s - '0';
      newNum[length] = inpNum[length];
      length++;
    }

    //mirror the palindrome
    rep(i, length>>1)
    {
      newNum[length >> 1 + i + 1] = inpNum[i];
    }

    if (greater(newNum, inpNum, length)) //if greater, then newNum is the final answer
    {
      rep(i, length)
      {
        printf("%d", newNum);
      }
      printf("\n");
      continue;
    }
    else
    {

    }

    
  }







  return OfTheKing;
}


int greater(vector<int> &newNumber, vector<int> &inputNumber, int length)
{
  gRep(i, (length >> 1), length)
  {
    if (newNumber[i] > inputNumber[i])
    {
      return 1;
    }
  }

  return 0;
}

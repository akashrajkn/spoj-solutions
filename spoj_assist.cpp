/*
  problem code: ASSIST
  problem number: 1798
  problem link: http://www.spoj.com/problems/ASSIST/
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

using namespace std;

#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define sc(a) scanf("%lld", &a)
#define pf(a) printf("%lld\n",a)
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define pb push_back

typedef pair<long long,long long> pii;
typedef long long ll;

int lucky[33810];
int actual[3001];

int main()
{
  int n,count;

  count= 1;
  //generate lucky numbers
  memset(lucky, 1, 33810*sizeof(int));
  lucky[1] = 0;
  for( int i=2; i<33810; ++i )
  {
    if(lucky[i])
    {
      actual[count++] = i;
      if(count>3001)
      {
        break;
      }
      int p = 0;
      for(int j=i+1; j<33810; ++j)
      {
        if(lucky[j])
        {
          p++;
          if(p==i)
          {
            lucky[j] = 0;
            p=0;
          }
        }
      }

    }
  }


  while(1)
  {
    scanf("%d", &n);

    if(n==0)
      break;

    printf("%d\n", actual[n]);
  }



  return 0;
}




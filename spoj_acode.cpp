/*
  problem code: ACODE
  problem number: 394
  problem link: http://www.spoj.com/problems/ACODE/
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
typedef long long int ll;

ll dp[5001];


int main()
{
  string s;

  while(1)
  {
    memset(dp,0, 5001*sizeof(ll));
    cin>>s;

    if(s=="0")
    {
      break;
    }

    int slen = s.length();
    int temp;
    dp[0]=1;

    for (int i = 1; i < slen; ++i)
    {
      temp = (s[i-1]-'0')*10 + s[i] -'0';

      if(s[i]-'0') //if current number is >=1--valid
      {
        dp[i]=dp[i-1];
      }
      // check if 2digit num is valid
      if(temp<=26 && temp>9)
      {
        dp[i] += dp[i-2<0?0:i-2];
      }
    }

    printf("%lld\n", dp[slen-1]);
  }

  return 0;
}



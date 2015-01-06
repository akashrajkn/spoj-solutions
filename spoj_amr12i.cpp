/*
  problem code: AMR12B
  problem number: 13042
  problem link: http://www.spoj.com/problems/AMR12B/
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

using namespace std;

#define OfTheKing 0
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
#define g_u getchar_unlocked() //if windows use getchar()

typedef pair<long long,long long> pii;
typedef long long ll;


//fast input function
inline void getInt( int &n )
{
  n=0;
  int ch=g_u;
  int sign=1;
  while( ch < '0' || ch > '9' )
  {
    if(ch=='-')
    {
      sign=-1;
    }
    ch=g_u;
  }
  while( ch >= '0' && ch <= '9' )
  {
    n=(n<<3)+(n<<1)+ ch-'0';
    ch=g_u;
  }
  n*=sign;
}


int main()
{
  int t, n, k;

  getInt(t);

  while(t--)
  {
    getInt(n);
    getInt(k);

    //char c[k];

    //scanf("%s", c);
    string c;

    cin>>c;

    char temp = c[0];
    int count=1; // to check the number of occurences of a particular char(consecutive)
    int ans = 0;
    int max = 0; //max lenght of consecutive chars --- this should at least be 'k'

    gRep(i,1,n+1)
    {
      if(temp==c[i])
      {
        count++;
      }
      else
      {
        if(count<=k)
        {
          ans++;
        }
        else
        {
          ans += (count+k-1)/k;  //ans += ceil(count/k); 
        }

        if(count> max)
        {
          max = count;
        }

        count = 1;
        temp = c[i];
      }
    }

    if(max>=k)
    {
      printf("%d\n", ans);
    }
    else
    {
      printf("-1\n");
    }

  }

  return OfTheKing;
}







/*
  problem code: DISUBSTR
  problem number: 1694
  problem link: http://www.spoj.com/problems/DISUBSTR/
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
#define g_u getchar() //if windows use getchar()

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


string s;
ll lcp(string, string);

int main()
{
  int t;
  getInt(t);

  while(t--)
  {
    cin>>s;

    int len = s.size();
    string temp;

    vector<string> v(len);

    rep(i, len)
    {
      temp  = s.substr(i, len);
      v[i] = temp;
    }

    sort(all(v)); // v----suffix array


    ll ans = v[0].size();

    gRep(i,1, len)
    {
      ans += ( v[i].size() -lcp(v[i], v[i-1]) );
    }

    pf(ans);
  }

  return 0;
}


ll lcp(string a, string b) // longest common prefix
{
  int lena = a.size();
  int lenb = b.size();

  if(lena>lenb)
  {
    swap(a,b);

    swap(lena, lenb);
  }

  int lcans = 0;

  rep(i, lena)
  {
    if(a[i]==b[i])
    {
      lcans++;
    }
    else
    {
      break;
    }
  }

  return lcans;
}


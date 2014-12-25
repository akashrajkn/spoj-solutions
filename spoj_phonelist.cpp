/*
  problem code: PHONELIST
  problem number: 4033
  problem link: http://www.spoj.com/problems/PHONELIST/
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
#define pb push_back

typedef pair<long long,long long> pii;
typedef long long ll;

int main()
{
  int t, n;
  int dirty =0;
  string p;

  scanf("%d",&t);

  while(t--)
  {
    scanf("%d", &n);
    vector<string> a(n);
    dirty = 0;

    rep(i,n)
    {
      cin>>p;
      a[i]=p;
    }

    sort(all(a));

    string prev = "init";

    rep(i,n)
    {
      int len = prev.length();

      string pres = a.at(i).substr(0,len);

      if(pres == prev)
      {
        cout<<"NO"<<endl;
        dirty = 1;
        break;
      }

      prev = a.at(i);
    }

    if(dirty==0)
    {
      cout<<"YES"<<endl;
    }
  }


  return 0;
}
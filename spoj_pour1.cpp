/*
  problem code: POUR1
  problem number: 25
  problem link: http://www.spoj.com/problems/POUR1/
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
#define gRep(i,p,n) for(long long i=p, i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define sc(a) scanf("%lld", &a)
#define pf(a) printf("%lld\n",a)
//#define g_u getchar_unlocked() //if windows use getchar()
#define g_u getchar()

typedef pair<int, int> pii;
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


int gcd(int a, int b)
{
  while(b!=0)
  {
    a%=b;
    a^=b;
    b^=a;
    a^=b;
  }

  return a;
}


//bool visited[40001][40001];
bool a_bfull[40001], a_bempty[40001], b_afull[40001], b_aempty[40001];

int bfs(int, int ,int);


int main()
{
  int t, a, b, c;

/*
  This soln is based on bfs
*/

  getInt(t);

  while(t--)
  {
    getInt(a);
    getInt(b);
    getInt(c);

    //memset(visited, 0, (a+1)*(b+1)*sizeof(bool));
    memset(a_bfull, 0, (a+1)*sizeof(bool));
    memset(a_bempty, 0, (a+1)*sizeof(bool));
    memset(b_afull, 0, (b+1)*sizeof(bool));
    memset(b_aempty, 0, (b+1)*sizeof(bool));

    printf("%d\n", bfs(a,b,c));
  }

  return OfTheKing;
}


int bfs(int a, int b, int c)
{
  if(c>a && c>b)
  {
    return -1;
  }

  queue< pair< pii, int> > q;
  bool ans = false;
  pair< pii, int > topQ;

  q.push( mp(mp(0,0),0) );
  //visited[0][0] = true;

  while(!q.empty())
  {
    topQ = q.front();
    q.pop();
    int atemp = topQ.first.first;
    int btemp = topQ.first.second;

    if(atemp==c || btemp==c)
    {
      ans = true;
      break;
    }

    //visited[atemp][btemp] = true;
    if(atemp==0)
    {
      b_aempty[btemp]= true;
    }
    if(btemp==0)
    {
      a_bempty[atemp]= true;
    }
    if(atemp==a)
    {
      b_afull[btemp] = true;
    }
    if(btemp==b)
    {
      a_bfull[atemp] = true;
    }

/*
    empty a vessel
    fill a vessel
    pour from one vessel to another either full/empty
*/

    //empty a vessel
    if(atemp!=0)
    {
      //if(visited[0][btemp]==false)
      if(b_aempty[btemp]==false)
      {
        q.push(mp(mp(0, btemp),topQ.second +1));
      }
    }
    if(btemp!=0)
    {
      //if(visited[atemp][0]==false)
      if(a_bempty[atemp]==false)
      {
        q.push(mp(mp(atemp, 0),topQ.second +1));
      }
    }

    //fill a vessel
    if(atemp!=a)
    {
      //if(visited[a][btemp]==false)
      if(b_afull[btemp]==false)
      {
        q.push(mp(mp(a, btemp),topQ.second +1));
      }
    }
    if(btemp!=b)
    {
      //if(visited[atemp][b]==false)
      if(a_bfull[atemp]==false)
      {
        q.push(mp(mp(atemp, b),topQ.second +1));
      }
    }

    //pour from 'a' vessel to 'b' vessel
    if(atemp!=0 && btemp!=b)
    {
      if(atemp>(b-btemp))
      {
        //if(visited[atemp+btemp-b][b]==false)
        if(a_bfull[atemp+btemp-b]==false)
        {
          q.push(mp(mp(atemp+btemp-b, b),topQ.second +1));
        }
      }
      else
      {
        //if(visited[0][btemp+atemp]==false)
        if(b_aempty[btemp+atemp]==false)
        {
          q.push(mp(mp(0, btemp+atemp),topQ.second +1));
        }
      }
    }
    //pour from 'b' vessel to 'a' vessel
    if(atemp!=a && btemp!=0)
    {
      if(btemp>(a-atemp))
      {
        //if(visited[a][btemp+atemp-a]==false)
        if(b_afull[btemp+atemp-a]==false)
        {
          q.push(mp(mp(a, btemp+atemp-a),topQ.second +1));
        }
      }
      else
      {
        //if(visited[btemp+atemp][0]==false)
        if(a_bempty[atemp+btemp]==false)
        {
          q.push(mp(mp(btemp+atemp, 0),topQ.second +1));
        }
      }
    }
  }

  if(ans)
  {
    return topQ.second;
  }

  return -1;
}

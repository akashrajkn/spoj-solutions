/*
problem code: RPLA
problem number: 11371
problem link: http://www.spoj.com/problems/RPLA/
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
#define g_u getchar()

typedef pair<long long, long long> pii;
typedef long long ll;


//fast input function
inline void getInt(int &n)
{
  n = 0;
  int ch = g_u;
  int sign = 1;
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


int max(int a, int b)
{
  return a>b ? a : b;
}

int t, r, n, r1, r2;
set< pair<int, int> > result; //pair<rank, empno>
bool visited[1001];
int inDegree[1001];
vector<int> graph[1001];
int bully[1001];

void dfs(int a, int b);


int main()
{
  getInt(t);

  rep(j, t)
  {
    getInt(n);
    getInt(r);

    memset(visited, false, n*sizeof(bool));
    memset(inDegree, 0, n*sizeof(int));
    memset(bully, 0, n*sizeof(int));

    result.clear(); //clear the result container

    rep(i, n)//clear the vector for this iteration
    {
      graph[i].clear();
    }

    rep(i, r) //r relations
    {
      getInt(r1);
      getInt(r2);

      graph[r2].PB(r1);
      inDegree[r1]++;
    }

    rep(i, n)
    {
      if (!inDegree[i]) //then i is a boss
      {
        dfs(i, 1);
      }
    }

    pair<int, int> tempp;
    int a = -1;
    int rank = 0;

    printf("Scenario #%d:\n", j+1);

    for (set< pair<int, int> >::iterator it = result.begin(); it != result.end(); it++)
    {
      tempp = *it;

      printf("%d %d\n", tempp.first, tempp.second);
    }
  }

  return OfTheKing;
}


void dfs(int u, int rank)
{
  int v;

  if (!visited[u])
  {
    visited[u] = true;
    bully[u] = rank;
  }
  else
  {
    if (result.find(MP(bully[u], u)) != result.end())
    {
      result.erase(MP(bully[u], u));
    }
    bully[u] = max(rank, bully[u]);
  }

  result.insert(MP(bully[u], u));

  for (int i = 0; i < graph[u].size(); ++i)
  {
    v = graph[u][i];

    if (!visited[v]) //not visited
    {
      dfs(v, 1 + bully[u]);
    }
    else //already visited
    {
      dfs(v, bully[u] + 1);
    }
  }

}
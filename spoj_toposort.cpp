/*
  problem code: TOPOSORT
  problem number: 9808
  problem link: http://www.spoj.com/problems/TOPOSORT/
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


int max( int a, int b )
{
  return a>b?a:b;
}


int n,m,x,y,counter;
vector<int> topoSort;
bool visited[10001];
vector<int> lorder[10001];
set<int> nextNode;
int inDegree[10001];

void topologySort();


int main()
{
  counter = 0;
  getInt(n);
  getInt(m);

  rep(i,m)
  {
    getInt(x);
    getInt(y);

    lorder[x-1].PB(y-1);
    inDegree[y - 1]++;
  }

  rep(i, n)
  {
    if (!inDegree[i]) //first work to be done will have indegree=0
    {
      nextNode.insert(i);
    }
  }

  topologySort();

  if (counter != n)
  {
    printf("Sandro fails.");
    return 0;
  }


  rep(i, n)
  {
    printf("%d ", topoSort[i]+1);
  }
  printf("\n");

  return OfTheKing;
}


void topologySort()
{
  int u, v;

  while (!nextNode.empty())
  {
    u = *nextNode.begin();
    
    nextNode.erase(nextNode.begin()); //remove the first one after it has been added to toposort vector

    topoSort.PB(u);
    counter++;

    for (int i = 0; i != lorder[u].size(); ++i)
    {
      inDegree[lorder[u][i]]--;
      if (!inDegree[lorder[u][i]])
        nextNode.insert(lorder[u][i]);
    }
  }

}
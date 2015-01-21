/*
  problem code: KGSS
  problem number: 3693
  problem link: http://www.spoj.com/problems/KGSS/
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
#define mp make_pair
#define all(c) c.begin(),c.end()
#define sc(a) scanf("%lld", &a)
#define pf(a) printf("%lld\n",a)
//#define g_u getchar_unlocked() //if windows use getchar()
#define g_u getchar()

typedef pair<long long,long long> pii;
typedef long long ll;
typedef unsigned long long llu;


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


int a[100005];


struct segTreeNode
{
  int max1, max2;

  void assignLeaf(int val)
  {
    max1 = val;
    max2 = 0;
  }

  void merge(segTreeNode &left, segTreeNode &right)
  {
    if(left.max1 > right.max1)
    {
      max1 = left.max1;
      max2 = max(left.max2, right.max1);
    }
    else
    {
      max1 = right.max1;
      max2 = max(left.max1, right.max2);
    }
  }

  int getValue()
  {
    return max1+max2;
  }

};


int sTreeSize(int n)
{
  int sz = 1;

  while(sz<n)
  {
    sz<<=1;
  }

  return sz<<1;
}


void buildSegTree(segTreeNode *nodes, int stIdx, int lo, int hi)
{
  if(lo==hi)
  {
    (nodes[stIdx]).assignLeaf(a[lo]);

    return;
  }

  int left = 2*stIdx;
  int right = left + 1;
  int mid = (lo+hi)/2;

  buildSegTree(nodes, left, lo, mid);
  buildSegTree(nodes, right, mid+1, hi);
  (nodes[stIdx]).merge(nodes[left], nodes[right]);
}


segTreeNode query(segTreeNode *nodes, int stIdx, int left, int right, int lo, int hi)
{
  if(lo==left && hi==right)
  {
    return nodes[stIdx];
  }

  int mid = (left+right)/2;

  if(lo>mid)
  {
    return query(nodes, stIdx*2+1, mid+1, right, lo, hi);
  }

  if(hi<=mid)
  {
    return query(nodes, stIdx*2, left, mid, lo, hi);
  }

  segTreeNode leftTreeResult = query(nodes, stIdx*2, left, mid, lo, mid);
  segTreeNode rightTreeResult = query(nodes, stIdx*2+1, mid+1, right, mid+1, hi);
  segTreeNode ans;
  ans.merge(leftTreeResult, rightTreeResult);

  return ans;
}


void updateSegTree(segTreeNode *nodes, int stIdx, int lo, int hi, int idx, int newVal)
{
  if(lo==hi)
  {
    (nodes[stIdx]).assignLeaf(newVal);

    return;
  }

  int mid = (lo+hi)/2;

  if(idx > mid)
  {
    updateSegTree(nodes, stIdx*2+1, mid+1, hi, idx, newVal);
  }
  else
  {
    updateSegTree(nodes, stIdx*2, lo, mid, idx, newVal);
  }

  (nodes[stIdx]).merge(nodes[stIdx*2+1], nodes[stIdx*2]);
}


int main()
{
  int n, q, x, y;
  char qu;

  getInt(n);

  rep(i,n)
  {
    getInt(a[i]);
  }

  //get size of segment tree
  segTreeNode nodes[sTreeSize(n)];

  //build segment tree
  buildSegTree(nodes, 1, 0, n-1);

  getInt(q);

  while(q--)
  {
    qu = g_u;
    getInt(x);
    getInt(y);

    if(qu=='Q')
    {
      //query
      segTreeNode result = query(nodes, 1, 0, n-1, x-1, y-1);

      printf("%d\n", result.getValue());
    }
    else if(qu=='U')
    {
      //update
      a[x-1] = y;
      updateSegTree(nodes, 1, 0 , n-1, x-1, y );
    }
  }

  return OfTheKing;
}






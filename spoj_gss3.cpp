/*
  problem code: GSS3
  problem number: 1716
  problem link: http://www.spoj.com/problems/GSS3/
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


int segTreeSize(int n) //size of segment tree array will 2*N if N(size of input array) is a power of 2
{
  int sz = 1;

  while(sz<n)
  {
    sz<<=1;
  }

  return sz<<1;
}


struct segTreeNode
{
  int prefixSum, suffixSum, maxSubarray, totalSum;

  void assignLeaf(int val) //assign value to the leaf
  {
    prefixSum = val;
    suffixSum = val;
    maxSubarray = val;
    totalSum = val;
  }

  void merge(segTreeNode &left, segTreeNode &right) //merge left and right subtrees
  {
    totalSum = left.totalSum + right.totalSum;
    prefixSum = max(left.prefixSum, left.totalSum+right.prefixSum);
    suffixSum = max(right.suffixSum, left.suffixSum+right.totalSum);
    maxSubarray = max(left.maxSubarray, max(right.maxSubarray, max(prefixSum, max(suffixSum, left.suffixSum+right.prefixSum))));
  }

  int getVal() //get maxSubarraySum for the present segTree Index
  {
    return maxSubarray;
  }
};


int a[50005];

void buildTree( segTreeNode *nodes, int stIdx, int lo, int hi)
{
  if(hi==lo)
  {
    //cout<<"leaf"<<hi<<" "<<a[lo]<<endl;
    (nodes[stIdx]).assignLeaf(a[lo]);
    return;
  }

  int left = 2*stIdx;
  int right = left+1;
  int mid = (lo + hi)/2;

  buildTree(nodes, left, lo, mid);
  buildTree(nodes, right, mid+1, hi);
  (nodes[stIdx]).merge(nodes[left], nodes[right]);
}


//nodes[stIdx]->takes care of the segment [left, right]
segTreeNode getValue( segTreeNode *nodes, int stIdx, int left, int right, int lo, int hi)
{
  if(lo==left && hi==right)
  {
    return nodes[stIdx];
  }

  int mid = (left + right)/2;

  if(lo>mid)
  {
    return getValue(nodes, stIdx*2 +1, mid+1, right, lo, hi );
  }

  if(hi<=mid)
  {
    return getValue(nodes, stIdx*2, left, mid, lo, hi);
  }

  segTreeNode leftTreeResult = getValue(nodes, stIdx*2, left, mid, lo, mid);
  segTreeNode rightTreeResult = getValue(nodes, stIdx*2+1, mid+1, right, mid+1, hi);
  segTreeNode ans;
  ans.merge(leftTreeResult, rightTreeResult);
  
  return ans;
}


void update(segTreeNode *nodes, int stIdx, int lo, int hi, int idx, int newVal)
{
  if(lo==hi) //implies it is a leaf node
  {
    nodes[stIdx].assignLeaf(newVal);
    return;
  }

  int mid = (lo+hi)/2;
  int left = 2*stIdx;
  int right = 2*stIdx + 1;

  if(idx <= mid)
  {
    update(nodes, left, lo, mid, idx, newVal);
  }
  else
  {
    update(nodes, right, mid+1, hi, idx, newVal);
  }

  nodes[stIdx].merge(nodes[left], nodes[right]);
}


int main()
{
  int n, m, x, y, q;

  //scanf("%d", &n);
  getInt(n);

  rep(i, n)
  {
    //scanf("%d", &a[i]);
    getInt(a[i]);
  }

  struct segTreeNode nodes[segTreeSize(n)]; //array represents the segment tree

  //cout<<segTreeSize(n)<<endl;

  buildTree(nodes, 1, 0 , n-1);

  getInt(m);
  //scanf("%d", &m);

  while(m--)
  {
    //scanf("%d", &q);
    //scanf("%d", &x);
    //scanf("%d", &y);
    getInt(q);
    getInt(x);
    getInt(y);

    if(q==0)
    {
      a[x] = y;
      update(nodes, 1, 0, n-1, x-1, y);
    }
    else if(q==1)
    {
      segTreeNode result = getValue(nodes, 1, 0, n-1, x-1, y-1);
      printf( "%d\n", result.getVal() );
    }
  }

  return OfTheKing;
}






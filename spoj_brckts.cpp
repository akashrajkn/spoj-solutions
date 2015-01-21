/*
  problem code: BRCKTS
  problem number: 61
  problem link: http://www.spoj.com/problems/BRCKTS/
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
  int unmatchOpen, unmatchClosed;

  void assignLeaf(char val) //assign value to the leaf
  {
    if(val=='(')
    {
      unmatchOpen = 1, unmatchClosed = 0;
    }
    else
    {
      unmatchOpen = 0, unmatchClosed = 1;
    }
  }

  void merge(segTreeNode &left, segTreeNode &right) //merge left and right subtrees
  {
    int matchNew = min(left.unmatchOpen, right.unmatchClosed);
    unmatchOpen = left.unmatchOpen + right.unmatchOpen - matchNew;
    unmatchClosed = left.unmatchClosed + right.unmatchClosed - matchNew;
  }

  int getVal() //get maxSubarraySum for the present segTree Index
  {
    //cout<<unmatchOpen<<" "<< unmatchClosed<<endl;
    return (unmatchOpen==0 && unmatchClosed==0);
  }
};


char a[30005];


void buildTree( segTreeNode *nodes, int stIdx, int lo, int hi)
{
  if(hi==lo)
  {
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


void update(segTreeNode *nodes, int stIdx, int lo, int hi, int idx, char newVal)
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
  /*
    This solution uses segment tree. The updation requires O(logN) time. querying is done in O(1)
    since we are just accessing the root of the segment tree.
  */

  char temp;
  int m; // number of queries
  int id,n;

  rep(i,10)
  {
    getInt(n);

    rep(j, n)
    {
      scanf("%c", &a[j]);
    }

    struct segTreeNode nodes[segTreeSize(n)]; //array represents the segment tree

    buildTree(nodes, 1, 0 , n-1); // build the segment tree

    getInt(m);//number of queries

    printf("Test %d:\n", i+1);

    while(m--)
    {
      getInt(id);

      if(id!=0)
      {
        if(a[id-1]=='(')
        {
          a[id-1] = ')';
        }
        else
        {
          a[id-1] = '(';
        }

        update(nodes, 1, 0, n-1, id-1, a[id-1]);
      }
      else if(id==0)
      {
        //segTreeNode result = getValue(nodes, 1, 0, n-1, 0, n-1);

        if(nodes[1].getVal())
        {
          printf("YES\n");
        }
        else
        {
          printf("NO\n");
        }
      }
    }
  }

  return OfTheKing;
}






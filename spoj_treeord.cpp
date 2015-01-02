/*
  problem code: NICEBTRE
  problem number: 13384
  problem link: http://www.spoj.com/problems/NICRBTRE/
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
typedef long long ll;

int genPost[8001];
int counter = 0;

void generatePostOrd( int in[], int pre[], int n );
int search(int a[], int r, int n);


int main()
{
  int n;

  /*
    recursion, preorder's first element is the root of the subtree, now find the index of the root in 
    inorder, all the elements before id[root] in inorder are in left subtree and all elements after root
    are in right subtree.

    for the left subtree again do the same, until we get index of root of the subtree is 0, if so, store
    it in an array genPost....

    if genPost(generated postorder) is same as the give post order, then it is a valid tree otherwise no. 
  */

  scanf("%d", &n);
  int in[n], pre[n], post[n];

  rep(i,n)
  {
    scanf("%d", &pre[i]);
  }

  rep(i,n)
  {
    scanf("%d", &post[i]);
  }

  rep(i,n)
  {
    scanf("%d", &in[i]);
  }

  generatePostOrd(in, pre, n);

  rep(i,n)
  {
    if(genPost[i]!=post[i])
    {
      printf("no\n");
      return 0;
    }
  }

  printf("yes\n");

  return 0;
}


void generatePostOrd( int in[], int pre[], int n )
{
  int root = find(in, pre[0], n); // current tree's root

  if(root!=0)
  {
    generatePostOrd(in, pre+1, root); //left sub tree
  }

  if(root!=n-1)
  {
    generatePostOrd(in+root+1, pre+root+1, n-root-1);  // right subtree
  }

  genPost[counter++] = pre[0];
}


int find(int a[], int r, int n)
{
  rep(i,n)
  {
    if(a[i]==r)
    {
      return i;
    }
  }

  return -1;
}
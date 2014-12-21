/*
  problem code: ACPC10D
  problem number: 7975
  problem link: http://www.spoj.com/problems/ACPC10D/
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
#define gRep(i,p,n) for(long long i=p, i<n; ++i)
#define mp make_pair
#define all(c) c.begin(),c.end()

typedef pair<long long,long long> pii;
typedef long long lli;

int a[100001][3];
int b[100001][3];

int main()
{
  //trigraphs
  int n,temp,temp1,count;

  count = 1;
  while(1)
  {
    scanf("%d",&n);

    if(n==0)
      break;

    rep(i,n)
    {
      scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }

    b[0][0]=INT_MAX;
    b[0][1]=a[0][1];
    b[0][2]=a[0][2] + a[0][1];

    for(int i=1; i<n; ++i)
    {
      //column = 0
      temp = b[i-1][0]<b[i-1][1] ? b[i-1][0]: b[i-1][1];
      b[i][0] = a[i][0]+temp;

      //column = 1 ---- i-1,0   i-1,1   i-1,2    i,0
      temp = b[i-1][0] < b[i-1][1]? b[i-1][0]: b[i-1][1];
      temp1 = b[i-1][2]<b[i][0]? b[i-1][2]:b[i][0];
      temp = temp<temp1 ? temp:temp1;

      b[i][1] = a[i][1]+temp;

      //column = 2 ----- i-1,1    i-1,2  i,1
      temp = b[i-1][1]<b[i-1][2] ? b[i-1][1]:b[i-1][2];
      temp = temp<b[i][1]?temp:b[i][1];

      b[i][2] = a[i][2] + temp;

    }

    //print answer
    printf("%d. %d\n", count, b[n-1][1]);

    count++;

  }

  return 0;
}



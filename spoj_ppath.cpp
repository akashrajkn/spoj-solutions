/*
problem code: PPATH
problem number: 1841
problem link: http://www.spoj.com/problems/PPATH/
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

using namespace std;

void findPrime();
int bfs();

vector <int> prime(10010);
bool visited[10010];
int b[5];
int n, m, yes;


int main()
{
  int t;
  for(int i=1; i<10010; i++)
  {
    prime[i]=1;
  }
  findPrime();
  memset(visited, 0, sizeof(visited));

  scanf( "%d", &t );

  while(t--)
  {
    scanf( "%d %d", &m, &n );

    printf("%d\n",bfs());
  }

  return 0;
}


void findPrime()
{
  for( int i=2; i<10010; i++ )
  {
    if(prime[i]==1)
    {
      for(int j=i+1; j<10010; j++)
      {
        if( j%i==0 )
        {
          prime[j]=0;
        }
      }
    }
  }
}


int bfs()
{
  if(m==n)
  {
    return 0;
  }

  memset(visited, 0, sizeof(visited));

  visited[m] = 1;
  queue< pair<int, int> > q;
  pair<int, int> one, temp;

  one = make_pair(m, 0);

  q.push(one);

  while(1)
  {
    temp = q.front();
    q.pop();

    b[1] = temp.first % 10;
    b[2] = (temp.first % 100)/10;
    b[3] = (temp.first % 1000)/100;
    b[4] = (temp.first % 10000)/1000;

    for (int i = 1; i <= 4; i++)
    {
      int c = temp.first - b[i]*pow( 10.0, i-1 );

      for (int j = 0; j <10 ; j++)
      {

        int newC = c + j*pow(10.0, i-1);

        if( newC == n )
        {
          return temp.second +1;
        }

        if( newC < 1000 || visited[newC]==1 || prime[newC]==0 )
          continue;

        visited[newC] = 1;

        pair<int, int> newTemp;
        newTemp = make_pair(newC, temp.second +1);
        q.push(newTemp);
      }
    }
  }
}






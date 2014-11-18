/*
  problem code: PT07Z
  problem number: 1437
  problem link: http://www.spoj.com/problems/PT07Z/
*/


#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <utility>
#include <climits>
#include <ctime>

using namespace std;

vector<int> tree[10000]; //to input the tree as adjacency list
int dist[10000]; //to find the farthest node from a node
int n, a, b; // n is the number of nodes

int que[10000]; //alternately queue<int> template can be used


/* perfoms a breadth-first search keeping the root at 'node' */
int bfs( int node )
{
  //queue<int> q;
  int top = 0, bot=0;

  memset(dist, -1, 10000*sizeof(int)); // initialize to -1, -1 indicates not visited

  dist[node] = 0;
  //q.push(node);
  que[bot++] = node;

  int max = dist[node];
  int max_node = node;

  while(bot>=top)
  {
    //int currNode = q.front();
    //q.pop();
    int currNode = que[top++];

    int sz = tree[currNode].size();

    for(int i =0; i<sz; ++i)
    {
      if(dist[tree[currNode][i]]==-1) //for a value >-1, it means that the node has been visited
      {
        //q.push(tree[currNode][i]);
        que[bot++] = tree[currNode][i];
        dist[tree[currNode][i]] = dist[currNode]+1;

        if(dist[currNode]+1 > max) // max dist path
        {
          max = dist[currNode]+1;
          max_node = tree[currNode][i];
        }
      }
    }
  }

  return max_node;
}


int main()
{
  scanf("%d", &n);

  for(int i=0; i<n-1; i++)
  {
    scanf("%d %d", &a, &b);
    tree[a-1].push_back(b-1);
    tree[b-1].push_back(a-1);
  }

  /* solution with two bfs */
  int node = bfs(0); //this finds the node 'q' farthest from any node 'p' (take any node as root and perform bfs)
  node = bfs(node); //this gives the farthest node from 'q' and gives the distance of the path

  printf("%d\n",dist[node]);

  return 0;
}





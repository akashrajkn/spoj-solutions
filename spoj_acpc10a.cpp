#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
  int a1, a2, a3;

  while(1)
  {
    scanf("%d %d %d", &a1, &a2, &a3);
    if(a1==0 && a2==0 && a3==0)
    {
      return 0;
    }

    int d1 = a2 - a1;
    int d2 = a3 - a2;

    if(d1==d2)
    {
      printf( "AP %d\n", a3+d1 );
    }
    else
    {
      int m1 = a2/a1;
      int m2 = a3/a2;

      if(m1==m2)
      {
        printf( "GP %d\n", a3*m1 );
      }
    }
  }

  return 0;
}

/*
  problem code: AMR11B
  problem number: 10229
  problem link: http://www.spoj.com/problems/AMR11B/
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

int l1,r1,t1,d1;

struct triangle
{
  int x1,y1,x2,y2,x3,y3;
  double area;
};

struct circle
{
  int x,y,r;
};

struct square
{
  int x,y,l;
};

void update(int fir, int sec); // updates the boundaries
bool insideTriangle(int one, int two, struct triangle triag);
bool insideCircle(int one, int two, int cx, int cy, int rad);
bool insideSquare(int one, int two, int xl, int yl, int l);


int main()
{
  int t,n;
  int numt, nums, numc; // boundaries for the outer square
  char inp;

/*
  basic idea: based on all the input points of square, circle and triangle, find a rectangular boundary
  name it as l1- left boundary, r1-right boundary, t1 and d1 are top and down boundaries respectively.

  Once this is calculated, just iterate through all points within the rectangle and check if each point
  is within the figures.... for optimization- first check if it is within square, if not within circle,
  if not within triangle

  to check if a point is within triangle, a very good and pretty optimal method is "barycentric co-ordinates"
  


  Barycentric coordinates: solve the equation system  p = p0 + (p1 - p0) * s + (p2 - p0) * t
  p is inside the triangle if s,t belong in the range [0,1] and all of s and t and (1-s-t) are positive

  s = 1/(2*Area)*(p0y*p2x - p0x*p2y + (p2y - p0y)*px + (p0x - p2x)*py);
  t = 1/(2*Area)*(p0x*p1y - p0y*p1x + (p0y - p1y)*px + (p1x - p0x)*py);
  Area = 1/2*(-p1y*p2x + p0y*(-p1x + p2x) + p0x*(p1y - p2y) + p1x*p2y);

  optimization can be done by calculating sdash = 2*|area|*s (i.e, without dividing by area factor)
  similary tdash

*/



  scanf("%d", &t);

  while(t--)
  {
    l1 = 10000;//intialization
    d1 = 10000;
    r1 = -10000;
    t1 = -10000;
    numt=0, nums=0, numc=0; // number of triangles, squares and circles
    scanf("%d", &n);

    struct triangle tri[50];
    struct circle cir[50];
    struct square sqr[50];

    rep(i,n)//input
    {
      cin>>inp;

      if(inp=='T')
      {
        scanf("%d %d %d %d %d %d",&((tri[numt]).x1),&((tri[numt]).y1),&((tri[numt]).x2),&((tri[numt]).y2),&((tri[numt]).x3),&((tri[numt]).y3));
        update((tri[numt]).x1 , (tri[numt]).y1);
        update((tri[numt]).x2 , (tri[numt]).y2);
        update((tri[numt]).x3 , (tri[numt]).y3);
        (tri[numt]).area = 1.0/2.0*(-(tri[numt]).y2*(tri[numt]).x3+(tri[numt]).y1*(-(tri[numt]).x2+(tri[numt]).x3)+(tri[numt]).x1*((tri[numt]).y2-(tri[numt]).y3)+(tri[numt]).x2*(tri[numt]).y3);
        //cout<< "area=="<<(tri[numt]).area <<endl;
        numt++;
      }
      else if(inp=='C')
      {
        scanf("%d %d %d",&((cir[numc]).x),&((cir[numc]).y),&((cir[numc]).r));
        update((cir[numc]).x - (cir[numc]).r, (cir[numc]).y);
        update((cir[numc]).x + (cir[numc]).r, (cir[numc]).y);
        update((cir[numc]).x , (cir[numc]).y + (cir[numc]).r);
        update((cir[numc]).x , (cir[numc]).y - (cir[numc]).r);
        numc++;
      }
      else if(inp=='S')
      {
        scanf("%d %d %d", &((sqr[nums]).x),&((sqr[nums]).y),&((sqr[nums]).l));
        update((sqr[nums]).x , (sqr[nums]).y);
        update((sqr[nums]).x + (sqr[nums]).l, (sqr[nums]).y);
        update((sqr[nums]).x , (sqr[nums]).y + (sqr[nums]).l);
        update((sqr[nums]).x + (sqr[nums]).l, (sqr[nums]).y + (sqr[nums]).l);
        nums++;
      }
    }

    //cout<<l1<<" "<<d1<<" "<<r1<<" "<<t1<<endl;

    int insqr = 0, incir=0;
    int numPoints = 0;
    for(int i = d1; i<=t1 ; ++i) // check if each point is inside the square, icrcle or triangle
    {
      for(int j = l1; j<=r1; ++j)
      {
        //cout<<i<<" "<<j<<endl;
        insqr = 0;
        incir = 0;
        rep(k, nums)
        {
          if(insideSquare(j, i, (sqr[k]).x, (sqr[k]).y, (sqr[k]).l))
          {
            numPoints++;
            insqr = 1; // if inside square, then dont check for other two
            break;
          }
        }

        if(insqr==0)
        {
          rep(k, numc)
          {
            if(insideCircle(j, i, (cir[k]).x, (cir[k]).y, (cir[k]).r ))
            {
              numPoints++;
              incir = 1;
              break;
            }
          }
        }

        if(incir ==0 && insqr==0)
        {
          rep(k, numt)
          {
            if(insideTriangle(j, i, tri[k]))
            {
              numPoints++;
              break;
            }
          }
        }
      }
    }

    printf("%d\n", numPoints );
  }

  return 0;
}


void update(int fir, int sec)
{
  if(fir<l1)
  {
    l1 = fir;
  }
  else if(fir>r1)
  {
    r1 = fir;
  }

  if(sec<d1)
  {
    d1 = sec;
  }
  else if(sec > t1)
  {
    t1 = sec;
  }
  //cout<<l1<<" "<<d1<<" "<<r1<<" "<<t1<<endl;
}


bool insideTriangle(int one, int two, struct triangle triag)
{
  double sdash, tdash, area;
  int x1,x2,x0,y1,y2,y0;

  x0 = triag.x1;
  x1 = triag.x2;
  x2 = triag.x3;
  y0 = triag.y1;
  y1 = triag.y2;
  y2 = triag.y3;

  //area = triag.area<0? (triag.area*-1.0): triag.area;

  //area = 1.0/2.0*(-y1*x2+y0*(-x1+x2)+x0*(y1-y2)+x1*y2);

  sdash = 1.0/(2*triag.area)*(y0*x2-x0*y2+(y2-y0)*one+(x0-x2)*two);
  tdash = 1.0/(2*triag.area)*(x0*y1-y0*x1+(y0-y1)*one+(x1-x0)*two);

  //sdash = (y0*x2-x0*y2+(y2-y0)*one+(x0-x2)*two);
  //tdash = (x0*y1-y0*x1+(y0-y1)*one+(x1-x0)*two);


  //cout<< sdash<<" "<<tdash <<" "<< area<<endl;

  if( sdash>=0 && tdash>=0 && (1-sdash-tdash)>=0 )
  //if( sdash >=0 && tdash>=0 &&  && ( sdash+tdash < 2*area ) )
  {
    return true;
  }

  return false;
}


bool insideCircle(int one, int two, int cx, int cy, int rad)
{
  int temp1 = (cx-one);
  int temp2 = (cy-two);

  if( (temp1*temp1 + temp2*temp2 - rad*rad)<=0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}


bool insideSquare(int one, int two, int xl, int yl, int l)
{
/*
  cout<< one<< " "<< two<<" "<< xl<< " "<< yl << " "<< l<<endl;
  bool yes = (one>=xl);
  cout<< yes <<endl;
  yes =   (one<=(xl+l));
  cout<<yes<<endl;
*/

  if(one>= xl && one <=(xl+l) && two>=yl && two <= (yl+l))
  {
    return true;
  }
  else
  {
    return false;
  }
}



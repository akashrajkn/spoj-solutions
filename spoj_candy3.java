import java.math.*;
import java.io.*;
import java.util.*;
import java.lang.*;

class spoj_candy3
{
  public static void main( String[] a )
  {
    BigInteger t, n, one, zer, n1, temp, sum;

    one = BigInteger.valueOf(1);
    zer = BigInteger.valueOf(0);
    Scanner sc = new Scanner(System.in);
    t = sc.nextBigInteger();

    while( t.compareTo(zer)>=1 )
    {
      n = sc.nextBigInteger();
      n1 = n;
      sum = zer;

      while( n1.compareTo(zer)>=1 )
      {
        temp = sc.nextBigInteger();
        sum = sum.add(temp);

        n1 = n1.subtract(one);
      }

      n1 = sum.mod(n);

      if( n1.equals(zer) )
      {
        System.out.println("YES");
      }
      else
      {
        System.out.println("NO");
      }

      t = t.subtract(one);
    }


  }
}

#include<bits/stdc++.h>
using namespace std;
class Bisection{
public:
   static double func(double x)
   {
       return pow(x,3)-2*x-5;
   }
   static double bisectionf(double a, double b)
   {
       if(func(a)*func(b)>=0)
       {
           cout<<"We can not apply bisection methods"<<endl;
       }else
       {
            double c = a;

      while((b-a)>=0.0002)
      {
          c = (a+b)/2;
          if(func(c)==0.0)
          {
              break;
          }
          else if (func(c)*func(a) < 0)
				b = c;
			else
				a = c;
      }
      cout<<c<<endl;
       }

   }

};
 int main()
    {
        double a,b;//,epsilon = 0.0002;
        cin>>a>>b;
        Bisection bisection(0.0002);

        bisection.bisectionf(a,b);
        return 0;
    }


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

double fun (int x,int n){

static double p =1, f= 1;
double r ;

if(n<=0)
  return 1;
else 
   r = fun(x,n-1);
   p = p*x;
   f = f*n;
   return p/f + r ;

}

int main()
{
  double res  = fun(3,10);
  //your_code_here
  cout<<std::fixed<<std::setprecision(8)<<res;

return 0;
}



#include<bits/stdc++.h>
using namespace std;

double pow(double x, int n)
{
  double res;

  if (n == 0) return 1;
  if (x == 1) return x;

  res = pow(x, n/2);
  if (n % 2 == 0) return res * res;
  else 
    {
      if (n > 0) return x * res * res;
      else return (res * res) / x;
    }

}
int main()
{
  double b; //denoting base
  cin >> b;
  int p; //denoting power
  cin >> p;

  double result = pow(b, p);
  cout << result << endl; 
  return 0;
}

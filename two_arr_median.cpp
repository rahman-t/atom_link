#include<bits/stdc++.h>
using namespace std;

int mini(int a, int b) 
{
  return (a < b) ? a : b;
}

int maxi(int x, int y)
{
  return (x > y) ? x : y;
}

double sortedArrayMedian(vector<int>& a, vector<int>& b)
{
  int min = 0, m, i, j;
  int max = a.size();
  int max_2 = b.size();
  int total = max + max_2;

  while (min <= max)
    {
      i = (min + max)/2;
      j = ((max + max_2 + 1) / 2) - i;

      if (i < max && j > 0 && b[j - 1] > a[i]) min = i + 1;

      else if (i > 0 && j > max_2 && b[j] < a[i - 1]) max = i - 1;

      else
	{
	  if (i == 0) m = b[j - 1];
	  else if (j == 0) m = a[i - 1];
	  else m = maxi(a[i - 1], b[j - 1]);
	  break;
		       
	}
    }
  if (total % 2 > 0) return (double)m;
  if (i == max) return (m + b[j]) / 2.0;
  if (j == max_2) return (m + a[i]) / 2.0;

  return (m + mini(a[i], b[j])) / 2.0;
}

int main()
{
  vector<int> arr1 = {900};
  vector<int> arr2 = {10, 13, 14};

  cout << sortedArrayMedian(arr1, arr2) << endl;
  return 0;
}

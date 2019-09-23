#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

/* Needs more work...
 */

int mini(int a, int b)
{
  return a < b ? a : b;
}

int maxi(int x, int y)
{
  return x > y ? x : y;
}

double sortedArrayMedian(vector<int>& a, vector<int>& b)
{
  int aSize = a.size();
  int bSize = b.size();

  if (aSize > bSize) return sortedArrayMedian(b, a);

  int min_i = 0, max_i = aSize, i, j;
  int h = (aSize + bSize + 1) / 2;
  int median = 0;

  while (min_i <= max_i)
    {
      i = (min_i + max_i) / 2;
      j = h - i;

      if (i < aSize && j > 0 && b[j - 1] > a[i]) min_i = i + 1;
      else if (i > 0 && j < bSize && b[j] < a[i - 1]) max_i = i - 1;
      else {
	if (i == 0) median = b[j - 1];
	else if (j == 0) median = a[i - 1];
	else median = maxi(a[i - 1], b[j - 1]);
	break;
      }
    }

  if ((aSize + bSize) % 2 != 0) return median;
  if (i == aSize) return (median + b[j]) / 2.0;
  if (j == bSize) return (median + a[i]) / 2.0;

  return (median + mini(a[i], b[j])) / 2.0;
}

int main()
{
  vector<int> arr1 = {4,5};
  vector<int> arr2 = {1,2,3};

  auto start = high_resolution_clock::now();
  cout << sortedArrayMedian(arr1, arr2) << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << " microseconds" <<endl;
  
  return 0;
}

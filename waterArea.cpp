/*The goal is to return the area capable of containing the most amount of water; given an array of non-negative integers, find two lines, which together with the x-axis forms a containter, such that the container contains the most water
 */
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<string> split_string(string);

int maxArea(vector<int>& arr)
{
  int start = 0;
  int end = arr.size() - 1;
  int area = 0;

  while (start < end)
    {
      area = max(area, min(arr[start], arr[end]) * (end - start));

      if (arr[start] < arr[end]) start++;
      else end--;
    }
  return area;
}

int main() 
{
  int s;
  cin >> s;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string str_temp_temp;
  getline(cin, str_temp_temp);
  
  vector<string> str_temp = split_string(str_temp_temp);
  vector<int> ar (s);

  for (int i = 0; i < ar.size(); i++)
    {
      int ar_items = stoi(str_temp[i]);
      ar[i] = ar_items;
    }
  
  cout <<  maxArea(ar) << endl;

  return 0;
}

vector<string> split_string(string str)
{
  vector<string> new_str;
  auto i = 0;
  auto pos = str.find(' ');
  
  while (pos != string::npos)
    {
      new_str.push_back(str.substr(i, pos - i));
      i = pos + 1;
      pos = str.find(' ', i);
    }
  new_str.push_back(str.substr(i, min(pos, str.size()) - i + 1));

  return new_str;
}

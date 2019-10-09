/*Source: Leetcode.com--Given a collection of distinct integers, return all possible permutations
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> split_string(string );

vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  res.push_back(nums);

  while(next_permutation(nums.begin(), nums.end()))
    {
      res.push_back(nums);
    }
    return res;
}

int main()
{
  int s;
  cin >> s;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string s_temp_temp;
  getline(cin, s_temp_temp);
  vector<string> s_temp = split_string(s_temp_temp);
  vector<int> s_final (s); 

  for (int i = 0; i < s; i++)
    {
      int s_items = stoi(s_temp[i]);
      s_final[i] = s_items;
    }
  vector<vector<int>> final = permute(s_final);
  
  for (int i = 0; i < final.size(); i++)
    {
      for (int j = 0; j < final[i].size(); j++)
	{
	  cout << final[i][j] << " ";
	}
      cout << endl;
    }

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
  new_str.push_back(str.substr(i, min(pos, str.length()) - i + 1));

  return new_str;
}

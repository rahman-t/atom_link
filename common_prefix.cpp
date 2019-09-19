#include<bits/stdc++.h>
using namespace std;

vector<string> split_string(string );

/*int min(int x, int y)
{
    return ((x<y) ? x : y);
}
*/

string commonPrefix(vector<string>& s)
{
  if ( s.empty()) return "";

  string pfx = s[0];
  for (int i = 1; i < s.size(); i++)
  {
    int len = min(pfx.size(), s[i].size());
    pfx = pfx.substr(0, len);
    for (int j = 0; j < len; j++)
    {
      if (pfx[j] != s[i][j])
      {
        pfx = pfx.substr(0, j);
        break;
      }
    }
    if (pfx == "") return "";
  }
  return pfx;
}
int main()
{
  string v_temp;
  getline(cin, v_temp);

  vector<string> v = split_string(v_temp);
  string res = commonPrefix(v);

  cout << res << endl;
  return 0;
}

vector<string> split_string(string str)
{
  vector<string> new_temp_v;
  int i = 0;
  int pos = str.find(' ');

  while (pos != -1)
  {
    new_temp_v.push_back(str.substr(i, pos - i));
    i = pos + 1;
    pos = str.find(' ', i)
  }
  new_temp_v.push_back(str.substr(i, min(pos, str.size()) - i + 1));

  return new_temp_v;
}

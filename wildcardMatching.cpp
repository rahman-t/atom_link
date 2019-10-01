/*Given 2 strings-the second to match with the first-implement wildcard pattern matching (similar to regex) '?' will match any character and '*' will match a sequence of chanracters including the empty sequence. Source: leetcode
*/

#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) 
{
  int len_s = s.size();
  int len_p = p.size();
  bool val [len_s + 1] [len_p + 1];

  memset(val, 0, sizeof(val));
  val[0][0] = 1;

  for (int i = 1; i <= len_p; i++)
    {
      if (p[i - 1] == '*') val[0][i] = val[0][i - 1];
    }

  for (int i = 1; i <= len_s; i++)
    {
      for (int j = 1; j <= len_p; j++)
	{
	  if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
	    {
	      val[i][j] = val[i - 1][j - 1];
	    }
	  else if (p[j - 1] == '*')
	    {
	      val[i][j] = val[i - 1][j] || val[i][j - 1];
	    }
	  else val[i][j] = 0;
	}
    }
  return val[len_s][len_p];
}

int main() 
{
  string str;
  getline(cin, str);

  string pattern;
  getline(cin, pattern);

  bool res = isMatch(str, pattern);

  if (res == 1) cout << "Match!\n";
  else cout << "Not a match\n";

  return 0;
}

#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(vector<string> &, int, int, string);

vector<string> generateParen(int n)
{
  vector<string> str;
  generateParenthesis(str, n, 0, "");
  return str;
}

void generateParenthesis(vector<string> &s, int left, int right, string expr)
{
  if (left == 0 &&  right == 0)
    {
      s.push_back(expr);
      return;
    }
  if (left > 0) generateParenthesis(s, left - 1, right + 1, expr + '{');
  if (right > 0) generateParenthesis(s, left, right - 1, expr + '}'); 
} 


int main() 
{
  int num;
  cin >> num;
  vector<string> res = generateParen(num);

  for (int i = 0; i < res.size(); i++) 
    {
      cout << res[i] << " " << endl;
    }
  return 0; 
}

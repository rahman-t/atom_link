#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
bool isValid(string str)
{
  stack<char> s;
  char c;

  for (int i = 0; i < str.size(); i++)
    {
      if (str[i] == '(' || str[i] == '{' || str[i] == '[')
	{
	  s.push(str[i]);
	}
      if (s.empty()) return false;
      switch (str[i])
	{
	case ')':
	  c = s.top();
	  s.pop();
	  if (c == '[' || c == '{') return false;
	  break;
	case '}':
	  c = s.top();
	  s.pop();
	  if (c == '[' || c == '(') return false;
	  break;
	case ']':
	  c = s.top();
	  s.pop();
	  if (c == '{' || c == '(') return false;
	  break;
	}
    }
  // is there any expression left in the stack ? If so, return false
  if (s.empty()) return true;

  return false;
}

int main()
{
  string n;
  getline(cin, n);

  auto start = high_resolution_clock::now(); 
  if (isValid(n))
    {
      cout << "True" << endl;
    }
    else 
      {
	cout << "False" << endl;
      }
  auto end = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(end - start);

  cout << duration.count() << " microseconds" << endl;

  return 0;
}

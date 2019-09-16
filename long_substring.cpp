#include<bits/stdc++.h>
using namespace std;

vector<string> split_string(string );

int findLongestSubstr(string s)
{
  int count = 1, max_count = 1, prev, len = s.size();
  int *visited = new int[sizeof(int) * 256];

  if (len == 0 ) return 0;

  for (int i = 0; i < 256; i++) {
	visited[i] = -1;
  }

  visited[s[0]] = 0;

  for (int i = 1; i < len; i++) {
	prev = visited[s[i]];

	if (prev == -1 || i - count > prev) count++;
	else {
		if (count > max_count) max_count = count;
		count = i - prev;
	}
	visited[s[i]] = i;
  }
  if (count > max_count) {
	max_count = count;
  }
  free(visited);
  return max_count;
}

int main ()
{
  string input;
  getline(cin, input);

  int result = findLongestSubstr(input);

  cout << result << endl;

  return 0;
}

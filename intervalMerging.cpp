/* Merging an array of overlapping intervals */

#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int>& x, vector<int>& y)
{
	return x[0] < y[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	if (intervals.empty()) return {};

	vector<vector<int>> res;
	int len = intervals.size();

	if (len < 2) return intervals;

	sort(intervals.begin(), intervals.end(), comp);
	res.push_back(intervals[0]);

	for (int i = 1; i < len; i++)
	{
		vector<int>& last_item = res.back();
		if (last_item[1] < intervals[i][0])
		{
			res.push_back(intervals[i]);
		}
		else
		{
			last_item[1] = max(last_item[1], intervals[i][1]);
		}
	}
	return res;
}

int main ()
{
	vector<vector<int>> arr = { {1, 3}, {2, 6}, {8, 10}, {15, 18}};

	vector<vector<int>> result = merge(arr);

	for(int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
	int res[m][n];
	for (int i = 0; i < m; i++) 
	{
		res[i][0] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		res[0][i] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			res[i][j] = res[i - 1][j] + res[i][j - 1];
		}
	}

	return res[m - 1][n - 1];
}

int main() 
{
	int input_1;
	int input_2;
	
	cin >> input_1;
	cin >> input_2;

	int result = uniquePaths(input_1, input_2);
	cout << result << endl;

	return 0;
}

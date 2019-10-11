#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
	if (n == 1) return 1;

	int first = 1, next = 2;

	for (int i = 3; i <= n; i++)
	{
		int temp = first + next;
		first = next;
		next = temp;
	}

	return next;
}
int main()
{
	int steps;
	cin >> steps;

	cout << climbStairs(steps) << endl;

	return 0;
}

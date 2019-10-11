#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<string> split_string (string );

vector<int>plusOne(vector<int>& digits)
{	
	int len = digits.size();

	digits[len - 1] += 1;
	int carry = digits[len - 1] / 10;
	digits[len - 1] = digits[len - 1] % 10;

	for (int i = len - 2; i >= 0; i--)
	{
		if (carry == 1)
		{
			digits[i] += 1;
			carry = digits[i] / 10;
			digits[i] = digits[i] % 10;
		}
	}
	if (carry == 1) digits.insert(digits.begin(), 1);

	return digits;
}

int main()
{	
	int size;
	cin >> size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string arr_temp_temp;
	getline(cin, arr_temp_temp);
	vector<string> arr_temp = split_string(arr_temp_temp);

	vector<int> arr(size);

	for (int i = 0; i < arr_temp.size(); i++)
	{
		int arr_items = stoi(arr_temp[i]);
		arr[i] = arr_items;
	}
	auto start = high_resolution_clock::now();
	plusOne(arr);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << duration.count() << " milliseconds" << endl;

	return 0;
}

vector<string> split_string (string str)
{
	vector<string> temp_str;
	auto i = 0;
	auto pos = str.find(' ');

	while (pos != string::npos)
	{
		temp_str.push_back(str.substr(i, pos - i));
		i = pos + 1;
		pos = str.find(' ', i);
	}
	temp_str.push_back(str.substr(i, min(pos, str.size()) - i + 1));

	return temp_str;
}

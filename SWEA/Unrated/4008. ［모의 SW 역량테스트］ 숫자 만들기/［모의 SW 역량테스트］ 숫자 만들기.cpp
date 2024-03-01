#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nums[13];
int maxRes, minRes;
int operators[4];

void init()
{
	maxRes = -2134567890;
	minRes = 2134567890;
	fill(nums, nums + 13, 0);
	fill(operators, operators + 4, 0);
	return;
}

void input()
{
	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> operators[i];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	return;
}

void dfs(int lev, int nowRes)
{
	if (lev == n - 1)
	{
		maxRes = max(maxRes, nowRes);
		minRes = min(minRes, nowRes);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!operators[i])
			continue;
		operators[i]--;
		if (i == 0)
			dfs(lev + 1, nowRes + nums[lev + 1]);
		else if (i == 1)
			dfs(lev + 1, nowRes - nums[lev + 1]);
		else if (i == 2)
			dfs(lev + 1, nowRes * nums[lev + 1]);
		else if (i == 3)
			dfs(lev + 1, nowRes / nums[lev + 1]);
		operators[i]++;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		input();
		dfs(0, nums[0]);
		cout << "#" << test_case << " " << maxRes - minRes << "\n";
	}
	return 0;
}
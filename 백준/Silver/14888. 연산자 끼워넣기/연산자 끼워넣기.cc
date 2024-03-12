#include <iostream>

using namespace std;

int n;
int nums[12];
int operators[4];
int minCalc = 2134567890, maxCalc = -1000000001;
int dat[12];

void dfs(int lev, int nowRes)
{
	if (lev == n)
	{
		minCalc = min(minCalc, nowRes);
		maxCalc = max(maxCalc, nowRes);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (operators[i] == 0)
			continue;
		operators[i]--;
		if (i == 0)
			dfs(lev+ 1, nowRes + nums[lev]);
		else if (i == 1)
			dfs(lev + 1, nowRes - nums[lev]);
		else if (i == 2)
			dfs(lev + 1, nowRes * nums[lev]);
		else if (i == 3)
		{
			if (nowRes < 0)
				dfs(lev + 1, -((-nowRes) / nums[lev]));
			else
				dfs(lev + 1, nowRes / nums[lev]);
		}
		operators[i]++;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	for (int i = 0; i < 4; i++)
		cin >> operators[i];
	dfs(1, nums[0]);

	cout << maxCalc << "\n";
	cout << minCalc << "\n";
	return 0;
}
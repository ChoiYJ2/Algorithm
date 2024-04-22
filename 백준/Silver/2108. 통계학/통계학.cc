#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> nums;
unordered_map<int, int> cnt;

int main()
{
	int n;
	int maxCnt = 0;
	double sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		nums.push_back(m);
		if (cnt.count(m) == 0)
			cnt.insert({ m, 1 });
		else
			cnt[m]++;
		sum += m;
		maxCnt = max(maxCnt, cnt[m]);
	}
	sort(nums.begin(), nums.end());

	if (round(sum / n) == -0)
		cout << 0 << "\n";
	else
		cout << round(sum / n) << "\n";
	cout << nums[n / 2] << "\n";

	int maxCntNum = 0;
	int flag = 0;
	if (n == 1)
		cout << nums[0] << "\n";
	else
	{
		for (int now : nums)
		{
			if (cnt[now] < maxCnt)
				continue;
			if (cnt[now] == maxCnt)
			{
				if (flag && now != maxCntNum)
				{
					cout << now << "\n";
					flag = 0;
					break;
				}
				flag = 1;
				maxCntNum = now;
			}
		}
	}
	if (flag)
		cout << maxCntNum << "\n";

	cout << nums[nums.size() - 1] - nums[0] << "\n";
	return 0;
}
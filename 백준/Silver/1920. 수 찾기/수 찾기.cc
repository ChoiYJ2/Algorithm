#include <iostream>
#include <algorithm>

using namespace std;
int nums[100001];

int bs(int start, int end, int tar)
{
	int mid = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (nums[mid] == tar)
			return tar;
		if (nums[mid] > tar)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		nums[i] = a;
	}
	sort(nums, nums + n);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (bs(0, n, a))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}
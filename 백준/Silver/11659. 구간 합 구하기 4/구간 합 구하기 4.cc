#include <iostream>

using namespace std;

int n, m;
int nums[100001];
int sums[100001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
		sums[i] = nums[i] + sums[i - 1];
	}
	for (int i = 0; i < m; i++)
	{
		int from, to, sum = 0;
		cin >> from >> to;
		sum = sums[to] - sums[from] + nums[from];
		cout << sum << "\n";
	}
	return 0;
}
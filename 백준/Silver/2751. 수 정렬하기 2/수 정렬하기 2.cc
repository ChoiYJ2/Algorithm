#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unordered_map<int, int> check;
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (check.count(m) != 0)
			continue;
		check.insert({ m, 1 });
		nums.push_back(m);
	}
	sort(nums.begin(), nums.end());

	for (int now : nums)
		cout << now << "\n";
	return 0;
}
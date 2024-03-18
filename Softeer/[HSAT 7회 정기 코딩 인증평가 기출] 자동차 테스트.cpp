#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> fuelEfficiency;

int bs(int start, int end, int target)
{
	int mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (fuelEfficiency[mid] == target)
			return mid;
		if (fuelEfficiency[mid] > target)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main()
{
	int n = 1, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		fuelEfficiency.push_back(m);
	}
	sort(fuelEfficiency.begin(), fuelEfficiency.end());

	for (int i = 0; i < q; i++)
	{
		int m;
		cin >> m;
		int idx = bs(0, fuelEfficiency.size() - 1, m);
		if (idx == -1)
			cout << "0\n";
		else
			cout << idx * (n - 1 - idx) << "\n";
	}
	return 0;
}

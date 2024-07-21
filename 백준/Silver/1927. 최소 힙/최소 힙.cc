#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	priority_queue<int, vector<int>, greater<int>> nums;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (nums.empty())
				cout << 0 << "\n";
			else
			{
				cout << nums.top() << "\n";
				nums.pop();
			}
		}
		else
			nums.push(x);
	}
	return 0;
}
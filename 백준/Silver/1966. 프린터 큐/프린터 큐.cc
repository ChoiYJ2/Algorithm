#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		int n, m;
		int priority[10];
		memset(priority, 0, sizeof(priority));
		queue<pair<int, int>> printer;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int p;
			cin >> p;
			printer.push({ i, p });
			priority[p]++;
		}

		int cnt = 0;
		for (int i = 9; i >= 1; i--)
		{
			if (priority[i] == 0)
				continue;
			int flag = 0;
			while (priority[i])
			{
				pair<int, int> now = printer.front();
				printer.pop();
				if (now.second == i)
				{
					priority[i]--;
					cnt++;
					if (now.first == m)
					{
						cout << cnt << "\n";
						flag = 1;
						break;
					}
				}
				else
					printer.push(now);
			}
			if (flag)
				break;
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, c;
int hive[11][11];
int visited[11][11];
int maxRevenue;
int rev;

void init()
{
	memset(hive, 0, sizeof(hive));
	memset(visited, 0, sizeof(visited));
	maxRevenue = 0;
	rev = 0;
}

void calcRevenue(int y, int x, int nowHoney, int offset)
{
	if (offset > m)
		return;
	int tmp = 0;
	for (int i = 0; i < offset; i++)
	{
		if (visited[y][x + i])
			tmp += (hive[y][x + i] * hive[y][x + i]);
	}
	rev = max(rev, tmp);

	for (int i = offset; i < m; i++)
	{
		if (nowHoney + hive[y][x + i] > c)
			continue;
		visited[y][x + i] = 1;
		calcRevenue(y, x, nowHoney + hive[y][x + i], i + 1);
		visited[y][x + i] = 0;
	}
}

void findSecond(int y, int x)
{
	for (int sy = y; sy < n; sy++)
	{
		int sx = 0;
		if (sy == y)
			sx = x;
		for (sx; sx <= n - m; sx++)
			calcRevenue(sy, sx, 0, 0);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> hive[i][j];
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x <= n - m; x++)
			{
				int tmpRev = 0;
				calcRevenue(y, x, 0, 0);
				tmpRev += rev;
				rev = 0;
				memset(visited, 0, sizeof(visited));
				findSecond(y, x + m);
				tmpRev += rev;
				rev = 0;
				memset(visited, 0, sizeof(visited));
				maxRevenue = max(maxRevenue, tmpRev);
			}
		}

		cout << "#" << test_case << " " << maxRevenue << "\n";
	}
	return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

int n, m, c;
int hive[11][11];
int visited[11][11];
int maxValue;
int value;

void init()
{
	maxValue = 0;
	value = 0;
	memset(visited, 0, sizeof(visited));
	memset(hive, 0, sizeof(hive));
}

void findMaxVal(int y, int x, int nowVal, int idx)
{
	if (nowVal > c)
		return;
	int tmp = 0;
	for (int i = 0; i < idx; i++)
	{
		if (visited[y][x + i])
			tmp += (hive[y][x + i] * hive[y][x + i]);
	}
	value = max(value, tmp);
	for (int i = idx; i < m; i++)
	{
		visited[y][x + i] = 1;
		findMaxVal(y, x, nowVal + hive[y][x + i], i + 1);
		visited[y][x + i] = 0;
	}
}

void findSecondMaxVal(int y, int x)
{
	for (int ny = y; ny < n; ny++)
	{
		if(ny == y)
		{
			for (int nx = x; nx < n - m + 1; nx++)
				findMaxVal(ny, nx, 0, 0);
		}
		else
		{
			for (int nx = 0; nx < n - m + 1; nx++)
				findMaxVal(ny, nx, 0, 0);
		}
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
			{
				cin >> hive[i][j];
			}
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n - m + 1; x++)
			{
				int tmpVal = 0;
				findMaxVal(y, x, 0, 0);
				tmpVal += value;
				value = 0;
				findSecondMaxVal(y, x + m);
				tmpVal += value;
				value = 0;
				maxValue = max(maxValue, tmpVal);
			}
		}
		cout << "#" << test_case << " " << maxValue << "\n";
	}
	return 0;
}
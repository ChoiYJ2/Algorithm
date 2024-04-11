#include <iostream>

using namespace std;

int n, k;
int map[8][8];
int visited[8][8];
int maxRoad;
int maxHeight;
int flag;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void dfs(int y, int x, int height, int road)
{
	maxRoad = max(maxRoad, road);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (visited[ny][nx])
			continue;

		if (height <= map[ny][nx])
		{
			if (!flag)
			{
				for (int dif = 1; dif <= k; dif++)
				{
					if (height > map[ny][nx] - dif)
					{
						flag = 1;
						visited[ny][nx] = 1;
						dfs(ny, nx, map[ny][nx] - dif, road + 1);
						visited[ny][nx] = 0;
					}
				}
				flag = 0;
			}
			continue;
		}
		visited[ny][nx] = 1;
		dfs(ny, nx, map[ny][nx], road + 1);
		visited[ny][nx] = 0;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		maxRoad = 0;
		maxHeight = 0;
		cin >> n >> k;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] > maxHeight)
					maxHeight = map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(map[i][j] == maxHeight)
				{
					visited[i][j] = 1;
					dfs(i, j, map[i][j], 1);
					visited[i][j] = 0;
				}
			}
		}

		cout << "#" << test_case << " " << maxRoad << "\n";
	}
	return 0;
}
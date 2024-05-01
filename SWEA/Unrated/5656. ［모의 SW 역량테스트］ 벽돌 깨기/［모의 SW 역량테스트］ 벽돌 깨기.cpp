#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, w, h;
int map[16][13];
int remainBricks;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Coord
{
	int y, x;
	int power;
};

void init()
{
	memset(map, 0, sizeof(map));
	remainBricks = 2134567890;
}

void bfs(int y, int x)
{
	queue<Coord> q;
	q.push({ y, x, map[y][x] });
	map[y][x] = 0;
	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();
		for (int offset = 0; offset < now.power; offset++)
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = now.y + dy[i] * offset;
				int nx = now.x + dx[i] * offset;

				if (ny < 0 || nx < 0 || ny >= h || nx >= w)
					continue;
				if (map[ny][nx] == 0)
					continue;
				q.push({ ny, nx, map[ny][nx] });
				map[ny][nx] = 0;
			}
		}
	}
}

void applyGravity()
{
	for (int x = 0; x < w; x++)
	{
		queue<int> q;
		for (int y = h - 1; y >= 0; y--)
		{
			if (map[y][x] == 0)
				continue;
			q.push(map[y][x]);
			map[y][x] = 0;
		}
		int y = h - 1;
		int lineSize = q.size();
		for (int offset = 0; offset < lineSize; offset++)
		{
			map[y - offset][x] = q.front();
			q.pop();
		}
	}
}

void calcRemain()
{
	int cnt = 0;
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if (map[y][x] == 0)
				continue;
			cnt++;
		}
	}
	remainBricks = min(remainBricks, cnt);
}

void dfs(int lev)
{
	int tmpMap[16][13];
	memcpy(tmpMap, map, sizeof(tmpMap));

	if (lev == n)
		return;

	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if (map[y][x] == 0)
				continue;
			bfs(y, x);
			applyGravity();
			dfs(lev + 1);
			calcRemain();
			memcpy(map, tmpMap, sizeof(map));
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		}

		// 벽돌 제거 및 중력 적용
		dfs(0);

		cout << "#" << test_case << " " << remainBricks << "\n";
	}
	return 0;
}
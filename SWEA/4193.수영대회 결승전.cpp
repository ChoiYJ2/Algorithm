#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int sea[16][16];
int visited[16][16];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

struct Coord
{
	int y, x;
	int nowTime;
}point[2];

void init()
{
	for (int i = 0; i < 16; i++)
	{
		fill(sea[i], sea[i] + 16, 0);
		fill(visited[i], visited[i] + 16, 0);
	}
}

int bfs(Coord& start)
{
	queue<Coord> q;
	q.push(start);
	visited[start.y][start.x] = 1;
	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		if (now.y == point[1].y && now.x == point[1].x)
			return now.nowTime;

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (sea[ny][nx] == 1)
				continue;
			if (visited[ny][nx])
				continue;
			
			if (sea[ny][nx] == 2 && now.nowTime % 3 != 2)
			{
				q.push({ now.y, now.x, now.nowTime + 1 });
				continue;
			}
			visited[ny][nx] = 1;
			q.push({ ny, nx, now.nowTime + 1 });
		}
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> sea[i][j];
		}
		for (int i = 0; i < 2; i++)
		{
			int y, x;
			cin >> y >> x;
			point[i] = { y, x, 0 };
		}

		cout << "#" << test_case << " " << bfs(point[0]) << "\n";
	}
	return 0;
}

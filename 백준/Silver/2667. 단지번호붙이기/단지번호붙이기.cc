#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
string map[26];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int visited[26][26];
priority_queue<int, vector<int>, greater<int>> houseCnt;

struct Point
{
	int y;
	int x;
};

void bfs(int y, int x)
{
	queue<Point> q;
	q.push({ y, x });
	visited[y][x] = 1;
	int house = 1;
	while (!q.empty())
	{
		Point now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (visited[ny][nx] || map[ny][nx] == '0')
				continue;
			visited[ny][nx] = 1;
			house++;
			q.push({ ny, nx });
		}
	}
	houseCnt.push(house);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '0' || visited[i][j])
				continue;
			bfs(i, j);
		}
	}

	int dangi = houseCnt.size();
	cout << dangi << "\n";
	for (int i = 0; i < dangi; i++)
	{
		cout << houseCnt.top() << "\n";
		houseCnt.pop();
	}
	return 0;
}
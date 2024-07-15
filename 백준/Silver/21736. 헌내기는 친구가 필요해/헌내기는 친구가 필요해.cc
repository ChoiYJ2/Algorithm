#include <iostream>
#include <queue>

using namespace std;

int n, m;
char campus[601][601];
bool visited[601][601];
int meet;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
struct Node
{
	int y, x;
}doyeon;

void bfs()
{
	queue<Node> q;
	q.push(doyeon);
	visited[doyeon.y][doyeon.x] = true;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visited[ny][nx] || campus[ny][nx] == 'X')
				continue;
			if (campus[ny][nx] == 'P')
				meet++;
			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> campus[i][j];
			if (campus[i][j] == 'I')
				doyeon = { i, j };
		}
	}
	bfs();
	if (meet == 0)
		cout << "TT";
	else
		cout << meet;
	return 0;
}
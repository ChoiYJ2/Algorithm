#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

char room[21][21];
int visited[21][21];
int minMove;
int w, h;
int clean;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Robot
{
	int y, x;
	int move;

	bool operator<(Robot a) const
	{
		if (move < a.move)
			return true;
		if (move > a.move)
			return false;
		return false;
	}
}start, last;

vector<Robot> dirty;

void init()
{

}

void bfs()
{
	priority_queue<Robot> pq;
	pq.push(start);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			visited[i][j] = 2134567890;
	}
	visited[start.y][start.x] = 0;
	while (!pq.empty())
	{
		Robot now = pq.top();
		pq.pop();
		if (room[now.y][now.x] == '*')
		{
			start = { now.y, now.x };
			minMove += visited[now.y][now.x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;
			if (room[ny][nx] == 'x')
				continue;
			int nextMove = now.move + 1;
			if (nextMove >= visited[ny][nx])
				continue;
			visited[ny][nx] = nextMove;
			pq.push({ ny, nx, nextMove });
		}
	}
}

int main()
{
	while(1)
	{
		init();
		bool valid = true;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> room[i][j];
				if (room[i][j] == 'o')
					start = { i, j };
				else if (room[i][j] == 'x')
					dirty.push_back({ i, j, 0 });
			}
		}
		last = start;
		for (int i = 0; i < dirty.size(); i++)
		{
			Robot now = dirty[i];
			int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];
				if (room[ny][nx] == 'x')
					cnt++;
			}
			if (cnt == 4)
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			int flag = 0;
			while (clean != dirty.size())
			{
				bfs();
				if (start.y == last.y && start.x == last.x)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				cout << -1 << "\n";
			else
				cout << minMove << "\n";
		}
		else
			cout << -1 << "\n";
	}
	return 0;
}
#include <iostream>
#include <vector>
//#include <algorithm>
#include <cstring>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int block[6][4] = { {-1, -1, -1, -1}, {1, 3, 0, 2}, {3, 0, 1, 2}, {2, 0, 3, 1}, {1, 2, 3, 0}, {1, 0, 3, 2} };
int n;
int map[101][101];
int maxScore;

struct Coord
{
	int y, x;
};

vector<Coord> wormhole[11];

void init()
{
	maxScore = 0;

	memset(map, 0, sizeof(map));
	//for (int i = 0; i < 101; i++)
		//fill(map[i], map[i] + 101, 0);

	for (int i = 0; i < 11; i++)
		wormhole[i].clear();
}

void startGame(int y, int x, int dir)
{
	int score = 0;
	int now_y = y;
	int now_x = x;
	int now_dir = dir;
	int flag = 0;
	while (1)
	{

		// 처음 위치로 돌아오면 종료
		if (now_y == y && now_x == x && flag == 1)
			break;
		flag = 1;
		now_y = now_y + dy[now_dir];
		now_x = now_x + dx[now_dir];
		// 블랙홀을 만났을 때
		if (map[now_y][now_x] == -1)
			break;
		// 벽에 부딪혔을 때
		if (now_y < 0 || now_x < 0 || now_y >= n || now_x >= n)
		{
			score++;
			now_y = now_y - dy[now_dir];
			now_x = now_x - dx[now_dir];
			if (now_dir % 2 == 0)
				now_dir++;
			else
				now_dir--;
		}
		// 블록에 부딪혔을 때
		if (1 <= map[now_y][now_x] && map[now_y][now_x] <= 5)
		{
			score++;
			now_dir = block[map[now_y][now_x]][now_dir];
		}
		// 웜홀을 만났을 때
		if (6 <= map[now_y][now_x] && map[now_y][now_x] <= 10)
		{
			int wormholeNum = map[now_y][now_x];
			if (now_y == wormhole[wormholeNum][0].y && now_x == wormhole[wormholeNum][0].x)
			{
				now_y = wormhole[wormholeNum][1].y;
				now_x = wormhole[wormholeNum][1].x;
			}
			else
			{
				now_y = wormhole[wormholeNum][0].y;
				now_x = wormhole[wormholeNum][0].x;
			}
		}
	}
	maxScore = max(maxScore, score);
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
			{
				cin >> map[i][j];
				if (map[i][j] >= 6)
					wormhole[map[i][j]].push_back({ i, j });
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] != 0)
					continue;
				for (int dir = 0; dir < 4; dir++)
					startGame(i, j, dir);
			}
		}

		cout << "#" << test_case << " " << maxScore << "\n";
	}
	return 0;
}
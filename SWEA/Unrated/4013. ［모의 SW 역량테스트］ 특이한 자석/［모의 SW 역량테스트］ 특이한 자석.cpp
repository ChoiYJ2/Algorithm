#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int k;
int magnet[5][8];
int score;
int isRotated[5];
int rotate_cnt;

struct MagnetInfo
{
	int num;
	int dir;
};

void init()
{
	for (int i = 0; i < 4; i++)
		memset(magnet[i], 0, sizeof(magnet[i]));
	memset(isRotated, 0, sizeof(isRotated));
	score = 0;
	rotate_cnt = 0;
}

void rotation(int num, int dir)
{
	queue<MagnetInfo> q;
	q.push({num, dir});
	while (!q.empty())
	{
		if (rotate_cnt == 4)
			return;

		MagnetInfo now = q.front();
		q.pop();

		int neighbor = now.num - 1;
		if (!isRotated[neighbor] && 1 <= neighbor)
		{
			if (magnet[now.num][6] != magnet[neighbor][2])
				q.push({ neighbor, now.dir * (-1) });
		}

		neighbor = now.num + 1;
		if (!isRotated[neighbor] && neighbor <= 4)
		{
			if (magnet[now.num][2] != magnet[neighbor][6])
				q.push({ neighbor, now.dir * (-1) });
		}

		if (isRotated[now.num])
			continue;

		int tmp[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		if(now.dir == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				int idx = (i + 1) % 8;
				tmp[idx] = magnet[now.num][i];
			}
		}
		else if (now.dir == -1)
		{
			for (int i = 0; i < 8; i++)
			{
				int idx = (i + 1) % 8;
				tmp[i] = magnet[now.num][idx];
			}
		}
		memcpy(magnet[now.num], tmp, sizeof(magnet[now.num]));
		isRotated[now.num] = 1;
		rotate_cnt++;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		cin >> k;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
				cin >> magnet[i][j];
		}
		// 회전 정보
		for (int i = 0; i < k; i++)
		{
			int magnet_num, direction;
			cin >> magnet_num >> direction;
			rotation(magnet_num, direction);
			memset(isRotated, 0, sizeof(isRotated));
			rotate_cnt = 0;
		}
		// 점수 계산
		for (int i = 1; i <= 4; i++)
			score += magnet[i][0] * pow(2, i - 1);

		cout << "#" << test_case << " " << score << "\n";
	}
	return 0;
}
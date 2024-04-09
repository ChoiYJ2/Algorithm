#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

struct Microbe
{
	int y, x;
	long long int num;
	int direction;
};

struct Info
{
	long long int num;
	int idx;
};

vector<Microbe> association;
Info map[101][101];

void init()
{
	association.clear();
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			map[i][j] = { 0, 0 };
	}
}

long long int calcRes()
{
	long long int sum = 0;
	for (Microbe& now : association)
	{
		if (now.num == 0)
			continue;
		sum += now.num;
	}
	return sum;
}

// 미생물 군집 모두 이동 -> 같은 칸에 위치하는 군집 확인 -> 이동 방향 결정
void moveMicrobeAsso()
{
	for (int i = 0; i < association.size(); i++)
	{
		Microbe now = association[i];
		if (now.num == 0)
			continue;

		int ny = now.y + dy[now.direction];
		int nx = now.x + dx[now.direction];

		// 약품이 칠해진 셀에 도달
		if (ny == 0 || nx == 0 || ny == n - 1 || nx == n - 1)
		{
			now.num /= 2;
			if (now.direction < 2)
				now.direction = (now.direction + 1) % 2;
			else
				now.direction = 2 + ((now.direction + 1) % 2);
		}

		// 미생물 군집 정보 업데이트
		association[i] = { ny, nx, now.num, now.direction };
	}
	return;
}

void checkOverlapAndDir()
{
	for (int i = 0; i < association.size(); i++)
	{
		Microbe now = association[i];
		if (now.num == 0)
			continue;

		// 셀에 이미 미생물 군집이 존재
		if (map[now.y][now.x].num != 0)
		{
			// 기존 미생물 군집 인덱스
			int idx = map[now.y][now.x].idx;
			// 기존 미생물 군집의 크기가 더 큼
			if (map[now.y][now.x].num > now.num)
			{
				association[idx].num += now.num;
				association[i].num = 0;
			}
			// 새로 도착한 미생물 군집의 크기가 더 큼
			else if(map[now.y][now.x].num < now.num)
			{
				map[now.y][now.x].num = now.num;
				map[now.y][now.x].idx = i;
				association[i].num += association[idx].num;
				association[idx].num = 0;
			}
		}
		// 비어있는 셀에 도착
		else
		{
			map[now.y][now.x].num = now.num;
			map[now.y][now.x].idx = i;
		}
	}
	return;
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		cin >> n >> m >> k;
		int y, x, nums, dir;
		for (int i = 0; i < k; i++)
		{
			cin >> y >> x >> nums >> dir;
			association.push_back({ y, x, nums, dir - 1 });
		}

		for (int nowTime = 1; nowTime <= m; nowTime++)
		{
			for (int i = 0; i < 101; i++)
			{
				for (int j = 0; j < 101; j++)
					map[i][j] = { 0, 0 };
			}
			moveMicrobeAsso();
			checkOverlapAndDir();
		}

		cout << "#" << test_case << " " << calcRes() << "\n";
	}
	return 0;
}
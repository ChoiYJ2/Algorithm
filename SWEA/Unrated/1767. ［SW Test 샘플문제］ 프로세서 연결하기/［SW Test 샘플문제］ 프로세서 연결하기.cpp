#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int map[13][13];
int maxCore;
int minWire;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
struct Core
{
	int y, x;
};
vector<Core> cores;

void init()
{
	maxCore = 0;
	minWire = 2134567890;
	memset(map, 0, sizeof(map));
	cores.clear();
}

void dfs(int nowCore, int nowWire, int idx)
{
	if (nowCore + (cores.size() - idx) < maxCore)
		return;

	if (idx == cores.size())
	{
		if (nowCore >= maxCore)
		{
			if (nowCore == maxCore)
				minWire = min(minWire, nowWire);
			else
			{
				minWire = nowWire;
				maxCore = nowCore;
			}
		}
		return;
	}

	for (int i = idx; i < cores.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int offset = 1;
			while (1)
			{
				int ny = cores[i].y + dy[j] * offset;
				int nx = cores[i].x + dx[j] * offset;

				// 전원 연결 성공
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				{
					for (int wire = 1; wire < offset; wire++)
						map[cores[i].y + dy[j] * wire][cores[i].x + dx[j] * wire] = 2;
					dfs(nowCore + 1, nowWire + offset - 1, i + 1);
					for (int wire = 1; wire < offset; wire++)
						map[cores[i].y + dy[j] * wire][cores[i].x + dx[j] * wire] = 0;
					break;
				}
				// 코어가 위치해있거나 전선이 위치해있는 경우
				else if (map[ny][nx] == 1 || map[ny][nx] == 2)
				{
					dfs(nowCore, nowWire, i + 1);
					break;
				}
				offset++;
			}
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
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1 && (i != 0 && i != n - 1 && j != 0 && j != n - 1))
					cores.push_back({ i, j });
			}
		}

		dfs(0, 0, 0);
		cout << "#" << test_case << " " << minWire << "\n";
	}
	return 0;
}
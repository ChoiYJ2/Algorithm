#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int cells[51][51];
int cnt;
int now_time;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

struct Location
{
	int y;
	int x;
	int vitality;
	int start_time;
};

vector<Location> disabled;
vector<Location> abled;

void init()
{
	for (int i = 0; i < 51; i++)
		memset(cells[i], 0, sizeof(cells[i]));
	cnt = 0;
	now_time = 0;
}

int ny, nx;
Location now;

bool isExist(Location target)
{
	if (target.y == ny && target.x == nx)
		return true;
	return false;
}

bool isActive(Location target)
{
	if (target.y == now.y && target.x == now.x)
		return true;
	return false;
}

void bfs()
{
	queue<Location> q;
	for (int i = 0; i < disabled.size(); i++)
		q.push({ disabled[i].y, disabled[i].x, disabled[i].vitality, disabled[i].start_time });
	now_time++;
	while (!q.empty())
	{
		now = q.front();
		q.pop();

		// ��� �ð��� �Ǹ� ����
		if (now_time == k)
			return;

		// �ش� �ð��� �����Ǿ��� �������� ����� ����
		if (now_time - now.start_time < now_time)
			now_time++;
		// ���� �ð��� ������ ���� �ð��� ���̰� ���� ����º��� ������ Ȱ��ȭ���� ����
		if (now.vitality > now_time - now.start_time)
		{
			q.push(now);
			continue;
		}
		// Ȱ�� ���°� �� ������ abled ���ͷ� �̵�
		auto pos = find_if(disabled.begin(), disabled.end(), isActive);
		disabled.erase(pos);
		abled.push_back(now);
		for (int i = 0; i < 4; i++)
		{
			ny = now.y + dy[i];
			nx = now.x + dx[i];

			// �ش� ��ġ�� �̹� ������ �����ϸ� ������ ����
			auto pos = find_if(disabled.begin(), disabled.end(), isExist);
			if (pos != disabled.end())
				continue;

			pos = find_if(abled.begin(), abled.end(), isExist);
			if (pos != abled.end())
				continue;

			q.push({ ny, nx, now.vitality, now_time });
			disabled.push_back({ ny, nx, now.vitality, now_time });
			cnt++;
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
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> cells[i][j];
				if (cells[i][j] != 0)
				{
					cnt++;
					disabled.push_back({ i, j, cells[i][j], now_time });
				}
			}
		}
		bfs();
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}
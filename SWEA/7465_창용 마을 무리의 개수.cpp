#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
vector<int> person[101];
int cnt;
int check[101];

void init()
{
	for (int i = 0; i < 101; i++)
		person[i].clear();
	memset(check, 0, sizeof(check));
	cnt = 0;
}

void bfs(int idx)
{
	queue<int> q;
	q.push(idx);
	check[idx] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < person[now].size(); i++)
		{
			if (check[person[now][i]])
				continue;
			q.push(person[now][i]);
			check[person[now][i]] = 1;
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
		cin >> n >> m;
		cin.ignore();
		for (int i = 0; i < m; i++)
		{
			int from, to;
			cin >> from >> to;
			person[from].push_back(to);
			person[to].push_back(from);
		}
		for (int i = 1; i <= n; i++)
		{
			if (check[i])
				continue;
			cnt++;
			bfs(i);
		}

		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}

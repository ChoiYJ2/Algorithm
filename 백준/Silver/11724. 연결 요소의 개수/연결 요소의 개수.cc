#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt;
bool visited[1001];
vector<int> graph[1001];

void bfs(int start)
{
	queue<int> q;
	q.push({ start });
	visited[start] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++)
		{
			int nextNum = graph[now][i];
			if (visited[nextNum])
				continue;
			visited[nextNum] = true;
			q.push(nextNum);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		cnt++;
		bfs(i);
	}

	cout << cnt;
	return 0;
}
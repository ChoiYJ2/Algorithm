#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int s, t;
vector<int> road[100001];
int goToWork[100001];
int goToHome[100001];
int nodeCnt;

void GoToCompany(int start, int end)
{
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		if (now == end)
			return;
		q.pop();
		for (int i = 0; i < road[now].size(); i++)
		{
			if(road[now][i] != end && road[now][i] != start)
				goToWork[road[now][i]] = 1;
			q.push(road[now][i]);
		}
	}
}

void GoToHome(int start, int end)
{
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		if (now == end)
			return;
		q.pop();
		for (int i = 0; i < road[now].size(); i++)
		{
			if (goToWork[road[now][i]] && !goToHome[road[now][i]])
				nodeCnt++;
			goToHome[road[now][i]] = 1;
			q.push(road[now][i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		road[from].push_back(to);
	}
	cin >> s >> t;
	GoToCompany(s, t);
	GoToHome(t, s);
	cout << nodeCnt;
	return 0;
}

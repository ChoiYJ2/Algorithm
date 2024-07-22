#include <iostream>
#include <queue>
#include <vector>
#define MAX 213456789

using namespace std;

int n, m;
struct Info
{
	int nowBarn, cows;

	bool operator<(Info a) const
	{
		if (cows < a.cows)
			return false;
		if (cows > a.cows)
			return true;
		return false;
	}
};
vector<Info> path[50001];
int stover[50001];

void dijkstra()
{
	priority_queue<Info> pq;
	pq.push({ 1, 0 });
	for (int i = 1; i <= n; i++)
		stover[i] = MAX;
	stover[1] = 0;
	while (!pq.empty())
	{
		Info now = pq.top();
		pq.pop();
		for (int i = 0; i < path[now.nowBarn].size(); i++)
		{
			int nextBarn = path[now.nowBarn][i].nowBarn;
			int nextStover = stover[now.nowBarn] + path[now.nowBarn][i].cows;
			if (nextStover >= stover[nextBarn])
				continue;
			stover[nextBarn] = nextStover;
			pq.push({ nextBarn, nextStover });
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		path[a].push_back({ b, c });
		path[b].push_back({ a, c });
	}
	dijkstra();
	cout << stover[n];
	return 0;
}
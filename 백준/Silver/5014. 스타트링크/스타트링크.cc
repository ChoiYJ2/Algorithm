#include <iostream>
#include <queue>
#define MAX 2134567890

using namespace std;

int f, s, g, u, d;
int visited[1000001];
int df[] = { -1, 1 };

struct Node
{
	int nowFloor, pressCnt;

	bool operator<(Node a) const
	{
		if (pressCnt < a.pressCnt)
			return false;
		if (pressCnt > a.pressCnt)
			return true;
		return false;
	}
};

void bfs()
{
	queue<Node> q;
	q.push({ s, 0 });
	for (int i = 1; i <= f; i++)
		visited[i] = MAX;
	visited[s] = 0;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			int nextFloor = now.nowFloor + df[i];
			if (nextFloor < 1 || nextFloor > f)
				continue;
			int nextPress = now.pressCnt + 1;
			if (nextPress >= visited[nextFloor])
				continue;
			visited[nextFloor] = nextPress;
			q.push({ nextFloor, nextPress });
		}
	}
}

int main()
{
	cin >> f >> s >> g >> u >> d;
	df[0] = df[0] * d;
	df[1] = df[1] * u;
	bfs();
	if (visited[g] == MAX)
		cout << "use the stairs";
	else
		cout << visited[g];
	return 0;
}
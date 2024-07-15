#include <iostream>
#include <queue>

using namespace std;

int n, k;
int visited[100001];
int map[100001];

struct Node
{
	int nowPos, passedTime;

	bool operator<(Node a) const
	{
		if (passedTime < a.passedTime)
			return false;
		if (passedTime > a.passedTime)
			return true;
		return false;
	}
};

void dijkstra()
{
	priority_queue<Node> pq;
	for (int i = 0; i < 100001; i++)
		visited[i] = 2134567890;
	visited[n] = 0;
	pq.push({ n, 0 });
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		int nextPos = now.nowPos - 1;
		int nextTime = now.passedTime + 1;

		if(nextPos >= 0 && nextTime < visited[nextPos])
		{
			visited[nextPos] = nextTime;
			pq.push({ nextPos, nextTime });
		}

		nextPos = now.nowPos + 1;
		if (nextPos <= 100000 && nextTime < visited[nextPos])
		{
			visited[nextPos] = nextTime;
			pq.push({ nextPos, nextTime });
		}

		nextPos = now.nowPos * 2;
		if (nextPos <= 100000 && nextTime < visited[nextPos])
		{
			visited[nextPos] = nextTime;
			pq.push({ nextPos, nextTime });
		}
	}
}

int main()
{
	cin >> n >> k;
	dijkstra();
	cout << visited[k];
	return 0;
}
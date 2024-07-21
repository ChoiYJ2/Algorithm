#include <iostream>
#include <queue>
#include <vector>
#define MAX 2134567890;

using namespace std;

int n, k;
int visited[100001];
struct Node
{
	int locate;
	int passedTime;

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
	pq.push({ n, 0 });
	for (int i = 0; i < 100001; i++)
		visited[i] = MAX;
	visited[n] = 0;
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		int nextLocate = now.locate * 2;
		int nextTime = now.passedTime;
		if (nextLocate <= 100000 && nextTime < visited[nextLocate])
		{
			visited[nextLocate] = nextTime;
			pq.push({ nextLocate, nextTime });
		}

		nextLocate = now.locate - 1;
		nextTime = now.passedTime + 1;
		if (nextLocate >= 0 && nextTime < visited[nextLocate])
		{
			visited[nextLocate] = nextTime;
			pq.push({ nextLocate, nextTime });
		}

		nextLocate = now.locate + 1;
		if (nextLocate <= 100000 && nextTime < visited[nextLocate])
		{
			visited[nextLocate] = nextTime;
			pq.push({ nextLocate, nextTime });
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
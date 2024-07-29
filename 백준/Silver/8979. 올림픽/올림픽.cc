#include <iostream>
#include <queue>

using namespace std;

int n, k;
struct Info
{
	int nation, g, s, b;

	bool operator<(Info a) const
	{
		if (g < a.g)
			return true;
		if (g > a.g)
			return false;
		if (s < a.s)
			return true;
		if (s > a.s)
			return false;
		if (b < a.b)
			return true;
		if (b > a.b)
			return false;
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	priority_queue<Info> pq;
	for (int i = 0; i < n; i++)
	{
		int nation, gold, silver, bronze;
		cin >> nation >> gold >> silver >> bronze;
		pq.push({ nation, gold, silver, bronze });
	}
	Info prev;
	int rank = 0;
	int stack = 0;
	while (!pq.empty())
	{
		Info now = pq.top();
		pq.pop();
		if (rank == 0)
			rank++;
		else
		{
			if (prev.g == now.g && prev.s == now.s && prev.b == now.b)
				stack++;
			else
			{
				rank++;
				if(stack != 0)
					rank += stack;
				stack = 0;
			}
		}
		if (now.nation == k)
			break;
		prev = now;
	}
	cout << rank;
	return 0;
}
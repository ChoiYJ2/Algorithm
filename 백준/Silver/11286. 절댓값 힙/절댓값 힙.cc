#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

struct cmp
{
	bool operator()(int a, int b) {
		int _a = abs(a), _b = abs(b);
		if (_a == _b)
			return (a > b);
		return (_a > _b);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, cmp> que;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		if (m == 0)
		{
			if (que.empty())
				cout << 0 << "\n";
			else
			{
				cout << que.top() << "\n";
				que.pop();
			}
		}
		else
			que.push(m);
	}
	return 0;
}
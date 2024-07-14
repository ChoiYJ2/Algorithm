#include <iostream>

using namespace std;

int n, m;
bool dat[9];
int numLog[9];

void dfs(int lev, int num)
{
	if (lev == m)
	{
		for (int i = 0; i < m; i++)
			cout << numLog[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = num; i <= n; i++)
	{
		if (dat[i])
			continue;
		numLog[lev] = i;
		dat[i] = true;
		dfs(lev + 1, i);
		dat[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	dfs(0, 1);
	return 0;
}
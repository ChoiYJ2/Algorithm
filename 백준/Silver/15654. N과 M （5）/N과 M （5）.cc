#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int numList[9];
int dat[9];
bool visited[10001];

void dfs(int lev, int idx)
{
	if (lev == m)
	{
		for (int i = 0; i < m; i++)
			cout << dat[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[numList[i]])
			continue;
		dat[lev] = numList[i];
		visited[numList[i]] = true;
		dfs(lev + 1, i);
		visited[numList[i]] = false;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> numList[i];
	sort(numList, numList + n);
	dfs(0, 0);
	return 0;
}
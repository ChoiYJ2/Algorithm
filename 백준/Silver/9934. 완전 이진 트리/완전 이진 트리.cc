#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int k;
vector<int> buildings;
vector<int> level[10];
int root;

void dfs(int now, int lev)
{
	if (lev == -1)
	{
		return;
	}
	level[lev].push_back(buildings[now]);
	dfs(now - pow(2, lev - 1), lev - 1);
	dfs(now + pow(2, lev - 1), lev - 1);
}

int main()
{
	cin >> k;
	do
	{
		int m;
		cin >> m;
		buildings.push_back(m);
	} while (getc(stdin) == ' ');
	root = buildings.size() / 2;
	dfs(root, k - 1);
	for (int i = k - 1; i >= 0; i--)
	{
		for (int j = 0; j < level[i].size(); j++)
			cout << level[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
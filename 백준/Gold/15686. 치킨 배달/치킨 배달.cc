#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dist[101][14];
int visited[14];
int chickenRoad = 2134567890;

struct Coord
{
	int y;
	int x;
};

vector<Coord> house;
vector<Coord> chicken;

void calcDist()
{
	for (int i = 0; i < house.size(); i++)
	{
		for (int j = 0; j < chicken.size(); j++)
			dist[i][j] = abs(house[i].y - chicken[j].y) + abs(house[i].x - chicken[j].x);
	}
}

void dfs(int lev, int idx)
{
	if ((chicken.size() > m && lev == m) || (lev == chicken.size()))
	{
		int sum = 0;
		for (int j = 0; j < house.size(); j++)
		{
			if (sum > chickenRoad)
				break;
			int miniDist = 2134567890;
			for (int i = 0; i < chicken.size(); i++)
			{
				if (!visited[i])
					continue;
				miniDist = min(miniDist, dist[j][i]);
			}
			sum += miniDist;
		}

		chickenRoad = min(chickenRoad, sum);
		return;
	}

	for (int i = idx; i < chicken.size(); i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		dfs(lev + 1, i);
		visited[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			if (k == 1)
				house.push_back({ i, j });
			else if (k == 2)
				chicken.push_back({ i, j });
		}
	}

	calcDist();
	dfs(0, 0);

	cout << chickenRoad;
	return 0;
}
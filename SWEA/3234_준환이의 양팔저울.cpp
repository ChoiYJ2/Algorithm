#include <iostream>
#include <cstring>

using namespace std;

int n;
int weights[10];
int exps[9] = { 1, 2, 4, 8, 16, 32, 64, 128, 256 };
int factorial[9] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };
int cnt;
int visited[10];
int all_sum;

void init()
{
	memset(weights, 0, sizeof(weights));
	memset(visited, 0, sizeof(visited));
	cnt = 0;
	all_sum = 0;
}

void dfs(int now_using, int leftSum, int rightSum)
{
	if (now_using == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (all_sum - leftSum <= leftSum)
		{
			cnt += exps[n - now_using] * factorial[n - now_using];
			return;
		}
		if (visited[i])
			continue;
		visited[i] = 1;
		dfs(now_using + 1, leftSum + weights[i], rightSum);
		visited[i] = 0;

		if (leftSum < (rightSum + weights[i]))
			continue;
		visited[i] = 1;
		dfs(now_using + 1, leftSum, rightSum + weights[i]);
		visited[i] = 0;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> weights[i];
			all_sum += weights[i];
		}
		dfs(0, 0, 0);
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}

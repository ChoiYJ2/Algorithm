#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int coin_value[101];
int values[10001];
int n, k;

void dp()
{
	values[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin_value[i]; j <= k; j++)
			values[j] += values[j - coin_value[i]];
	}
	cout << values[k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> coin_value[i];
	dp();
	return 0;
}
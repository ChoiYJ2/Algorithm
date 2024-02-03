#include <iostream>
#include <cstring>

using namespace std;

int arr[501][501];
int new_arr[501][501];

void input(int _n)
{
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _n; j++)
			cin >> arr[i][j];
	}
	return;
}

void rotation(int _n, int _d)
{
	memcpy(new_arr, arr, sizeof(new_arr));
	int half = _n / 2;
	for (int i = 0; i < (_d / 45); i++)
	{
		// 주 대각선[j][j] -> 가운데 열[j][half]
		for (int j = 0; j < _n; j++)
			new_arr[j][half] = arr[j][j];
		// 가운데 열[j][half] -> 부 대각선[_n - j - 1][j]
		for (int j = 0; j < _n; j++)
			new_arr[j][_n - j - 1] = arr[j][half];
		// 부 대각선[_n - j - 1][j] -> 가운데 행[half][j]
		for (int j = 0; j < _n; j++)
			new_arr[half][j] = arr[_n - j - 1][j];
		// 가운데 행[half][j] -> 주 대각선[j][j]
		for (int j = 0; j < _n; j++)
			new_arr[j][j] = arr[half][j];
		memcpy(arr, new_arr, sizeof(arr));
	}
}

void re_rotation(int _n, int _d)
{
	memcpy(new_arr, arr, sizeof(new_arr));
	int half = _n / 2;
	for (int i = 0; i < (_d / 45); i++)
	{
		// 주 대각선[j][j] -> 가운데 행[half][j]
		for (int j = 0; j < _n; j++)
			new_arr[half][j] = arr[j][j];
		// 가운데 행[half][j] -> 부 대각선[_n - j - 1][j]
		for (int j = 0; j < _n; j++)
			new_arr[_n - j - 1][j] = arr[half][j];
		// 부 대각선[_n - j - 1][j] -> 가운데 열[j][half]
		for (int j = 0; j < _n; j++)
			new_arr[_n - j - 1][half] = arr[_n - j - 1][j];
		// 가운데 열[j][half] -> 주 대각선[j][j]
		for (int j = 0; j < _n; j++)
			new_arr[_n - j - 1][_n - j - 1] = arr[_n - j - 1][half];
		memcpy(arr, new_arr, sizeof(arr));
	}
}

void print(int _n)
{
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, d;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		cin >> n >> d;
		memset(arr, 0, sizeof(arr));
		memset(new_arr, 0, sizeof(new_arr));
		input(n);
		if (d >= 0)
			rotation(n, d);
		else if (d < 0)
			re_rotation(n, -d);
		print(n);
	}
	return 0;
}
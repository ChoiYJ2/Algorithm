#include <iostream>

using namespace std;

int sosoo[1001];

void primeNumber()
{
	for (int i = 2; i <= 1000; i++)
		sosoo[i] = i;

	for (int i = 2; i <= 1000; i++)
	{
		if (sosoo[i] == 0)
			continue;
		for (int j = 2 * i; j <= 1000; j += i)
			sosoo[j] = 0;
	}
}

int main()
{
	int cnt = 0;
	int n;
	cin >> n;
	primeNumber();
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (sosoo[num] != 0)
			cnt++;
	}
	cout << cnt;
	return 0;
}
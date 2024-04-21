#include <iostream>

using namespace std;

int primeNum[1000001];

void findPrimeNumber()
{
	for (int i = 2; i <= 1000000; i++)
		primeNum[i] = i;

	for (int i = 2; i <= 1000000; i++)
	{
		if (primeNum[i] == 0)
			continue;
		for (int j = 2 * i; j <= 1000000; j += i)
			primeNum[j] = 0;
	}
}

int main()
{	
	int n, m;
	cin >> n >> m;
	findPrimeNumber();
	for (int i = n; i <= m; i++)
	{
		if (primeNum[i] == 0)
			continue;
		cout << primeNum[i] << "\n";
	}
	return 0;
}
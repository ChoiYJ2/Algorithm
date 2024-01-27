#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> primeNums;
bool check[1000001];
int prime_size;

void checkPrime()
{
	for (int i = 2; i < 1000001; i++)
	{
		if (check[i])
			continue;
		for(int j = i * 2; j < 1000001; j += i)
			check[j] = true;
	}
}

void calcLCM()
{
	if (prime_size >= 2)
	{
		long long int lcm = primeNums[0];
		for (int i = 1; i < prime_size; i++)
		{
			int gcd = 1;
			if (lcm % primeNums[i] == 0)
				gcd = primeNums[i];
			lcm *= primeNums[i];
			lcm /= gcd;
		}
		cout << lcm;
	}
	else
		cout << primeNums[0];
	return;
}

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	checkPrime();
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (!check[m])
			primeNums.push_back(m);
	}
	if (primeNums.empty())
	{
		cout << "-1";
		return 0;
	}
	prime_size = primeNums.size();
	calcLCM();
	return 0;
}
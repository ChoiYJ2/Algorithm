#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt = 1;
	int now = 666;
	while (1)
	{
		if (cnt == n)
			break;
		now++;

		int num = 0;
		int tmp = now;
		while (1)
		{
			if (num >= 3)
			{
				cnt++;
				break;
			}
			if (tmp == 0)
				break;
			if (tmp % 10 == 6)
				num++;
			else
				num = 0;
			tmp /= 10;
		}
	}
	cout << now;
	return 0;
}
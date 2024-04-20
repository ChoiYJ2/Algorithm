#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int twoCnt = 0;
	int fiveCnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int res = i;
		while(res != 0)
		{
			if (res % 2 != 0)
				break;				
			twoCnt++;
			res /= 2;
		}

		res = i;
		while(res != 0)
		{
			if (res % 5 != 0)
				break;
			fiveCnt++;
			res /= 5;
		}
	}
	cout << min(twoCnt, fiveCnt);
	return 0;
}
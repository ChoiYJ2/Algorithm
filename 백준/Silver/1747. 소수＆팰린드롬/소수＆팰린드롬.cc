#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n;
	cin >> n;
	int num = stoi(n);
	for(int j = num; j <= 1003002; j++)
	{
		int pal_flag = 1;
		string a = to_string(j);
		int numSize = a.length();
		// 팰린드롬 체크
		for (int i = 0; i < numSize / 2; i++)
		{ 
			// 팰린드롬 아니면 탈출
			if (a[i] != a[numSize - 1 - i])
			{
				pal_flag = 0;
				break;
			}
		}
		// 팰린드롬 o -> 소수 체크
		if(pal_flag)
		{
			int prime_flag = 1;
			for (int i = 2; i < j; i++)
			{
				// 팰린드롬 & 소수 x -> 다시 탐색
				if (j % i == 0 || j == 1)
				{
					prime_flag = 0;
					break;
				}
			}
			// 팰린드롬 & 소수 -> 탈출
			if (j != 1 && prime_flag)
			{
				cout << j;
				return 0;
			}
		}
	}
	return 0;
}
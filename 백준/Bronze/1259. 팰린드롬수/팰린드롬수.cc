#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num;
	while (1)
	{
		cin >> num;
		if (num == "0")
			break;
		int half = num.size() / 2;
		int back = num.size() - 1;
		int flag = 0;
		for (int i = 0; i < half; i++)
		{
			if (num[i] != num[back - i])
			{
				cout << "no\n";
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "yes\n";
	}
	return 0;
}
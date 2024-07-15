#include <iostream>

using namespace std;

bool setS[21];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string command;
		int num;
		cin >> command;
		if (command == "add")
		{
			cin >> num;
			if (!setS[num])
				setS[num] = true;
		}
		else if (command == "remove")
		{
			cin >> num;
			if (setS[num])
				setS[num] = false;
		}
		else if (command == "check")
		{
			cin >> num;
			if (setS[num])
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command == "toggle")
		{
			cin >> num;
			setS[num] = !setS[num];
		}
		else if (command == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				if (setS[i])
					continue;
				setS[i] = true;
			}
		}
		else if (command == "empty")
		{
			for (int i = 1; i <= 20; i++)
			{
				if (!setS[i])
					continue;
				setS[i] = false;
			}
		}
	}
	return 0;
}
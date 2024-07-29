#include <iostream>
#include <string>

using namespace std;

void checkQuality(string& now)
{
	int isInvalid = 0;
	if (now.find('a') == string::npos && now.find('e') == string::npos && now.find('i') == string::npos && now.find('o') == string::npos && now.find('u') == string::npos)
		isInvalid++;
	
	int flag = 0;
	for (int i = 0; i < now.length() - 1; i++)
	{
		char first = now[i];
		char second = now[i + 1];
		if ((first != 'e' && first != 'o') && first == second)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		isInvalid++;

	if (now.length() >= 2)
	{
		for (int i = 0; i < now.length() - 2; i++)
		{
			flag = 0;
			char f = now[i];
			char s = now[i + 1];
			char t = now[i + 2];
			if (f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u' || f == 'y')
				flag++;
			if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y')
				flag++;
			if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u' || t == 'y')
				flag++;
			if (flag == 3)
				break;
			if (flag == 0)
			{
				flag = -1;
				break;
			}
		}
		if (flag == -1 || flag == 3)
			isInvalid++;
	}
	if (isInvalid > 0)
		cout << "<" << now << "> is not acceptable.\n";
	else
		cout << "<" << now << "> is acceptable.\n";
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (1)
	{
		string test;
		cin >> test;
		if (test == "end")
			break;
		checkQuality(test);
	}
	return 0;
}
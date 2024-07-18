#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	unordered_map<string, string> poketmon;
	unordered_map<string, string> poketmonNum;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		poketmon.insert({ name, to_string(i)});
		poketmonNum.insert({ to_string(i), name});
	}

	for (int i = 0; i < m; i++)
	{
		string question;
		cin >> question;
		if (question[0] - 'A' < 0)
			cout << poketmonNum[question] << "\n";
		else
			cout << poketmon[question] << "\n";
	}
	return 0;
}
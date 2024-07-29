#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, cnt = 0;
	char game;
	unordered_map<char, int> gamePlayers;
	gamePlayers.insert({ 'Y', 1 });
	gamePlayers.insert({ 'F', 2 });
	gamePlayers.insert({ 'O', 3 });
	unordered_map<string, bool> played;
	cin >> n >> game;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		if (played.count(name) != 0)
			continue;
		played.insert({ name, true });
		cnt++;
	}
	cout << cnt / gamePlayers[game];
	return 0;
}
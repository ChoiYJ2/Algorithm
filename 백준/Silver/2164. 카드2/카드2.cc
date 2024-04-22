#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	queue<int> cards;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cards.push(i);
	while (cards.size() != 1)
	{
		cards.pop();
		int now = cards.front();
		cards.push(now);
		cards.pop();
	}
	cout << cards.front();
	return 0;
}
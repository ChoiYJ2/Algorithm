#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int turn = n / 3;
	n %= 3;
	if ((turn + n) % 2 == 0)
		cout << "CY";
	else
		cout << "SK";
	return 0;
}
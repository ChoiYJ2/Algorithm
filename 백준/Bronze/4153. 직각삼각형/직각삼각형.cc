#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a + b + c == 0)
			break;
		if (a > b && a > c)
		{
			if (a == sqrt(b * b + c * c))
				cout << "right\n";
			else
				cout << "wrong\n";
		}
		else if (b > a && b > c)
		{
			if (b == sqrt(a * a + c * c))
				cout << "right\n";
			else
				cout << "wrong\n";
		}
		else if (c > a && c > b)
		{
			if (c == sqrt(a * a + b * b))
				cout << "right\n";
			else
				cout << "wrong\n";
		}
	}
	return 0;
}
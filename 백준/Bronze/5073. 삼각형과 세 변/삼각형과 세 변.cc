#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0 && a == b && b == c)
			break;
		int maximum = max(a, max(b, c));
		if (a + b + c - maximum <= maximum)
			cout << "Invalid\n";
		else
		{
			if (a == b && b == c)
				cout << "Equilateral\n";
			else if (a == b || b == c || a == c)
				cout << "Isosceles\n";
			else
				cout << "Scalene\n";
		}
	}
	return 0;
}
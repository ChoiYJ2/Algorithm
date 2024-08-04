#include <iostream>
#include <cstring>

using namespace std;

int chargeA[10001], chargeB[10001];

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		memset(chargeA, 0, sizeof(chargeA));
		memset(chargeB, 0, sizeof(chargeB));
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;
		chargeB[0] = q;
		for (int water = 1; water <= w; water++)
		{
			chargeA[water] = chargeA[water - 1] + p;
			chargeB[water] = chargeB[water - 1];
			if (water <= r)
				continue;
			chargeB[water] += s;
		}
		cout << "#" << test_case << " " << min(chargeA[w], chargeB[w]) << "\n";
	}
	return 0;
}
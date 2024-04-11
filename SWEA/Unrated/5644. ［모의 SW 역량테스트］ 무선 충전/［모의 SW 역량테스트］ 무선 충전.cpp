#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int m, a;
int dy[] = { 0, -1, 0, 1, 0 };
int dx[] = { 0, 0, 1, 0, -1 };
int routeA[101], routeB[101];
int chargeMax;

struct Battary
{
	int y, x;
	int coverage, power;
};

struct Coord
{
	int y;
	int x;
}userA, userB;

vector<Battary> bc;
int availableA[8];
int availableB[8];
int availableACnt, availableBCnt;

void init()
{
	chargeMax = 0;
	memset(routeA, 0, sizeof(routeA));
	memset(routeB, 0, sizeof(routeB));
	bc.clear();
	memset(availableA, 0, sizeof(availableA));
	memset(availableB, 0, sizeof(availableB));
	userA = { 1, 1 };
	userB = { 10, 10 };
	availableACnt = 0, availableBCnt = 0;
}

void findBC(Coord& _a, Coord& _b)
{
	int distA = 0, distB = 0;
	for (int i = 0; i < a; i++)
	{
		Battary& now = bc[i];
		distA = abs(_a.y - now.y) + abs(_a.x - now.x);
		distB = abs(_b.y - now.y) + abs(_b.x - now.x);

		if (distA <= now.coverage)
		{
			availableA[i] = 1;
			availableACnt++;
		}
		if (distB <= now.coverage)
		{
			availableB[i] = 1;
			availableBCnt++;
		}
	}
}

void selectAndCalc()
{
	int chargeA = 0, chargeB = 0;
	int tmpCharge = 0;
	for (int i = 0; i < a; i++)
	{
		int flag = 0;
		if (availableA[i] == 0)
			continue;
		chargeA = bc[i].power;
		for (int j = 0; j < a; j++)
		{
			if (availableB[j] == 0)
				continue;
			if (i == j)
			{
				flag = 1;
				chargeA = bc[i].power / 2;
				chargeB = bc[j].power / 2;
			}
			else
			{
				if (flag)
				{
					chargeA *= 2;
					flag = 0;
				}
				chargeB = bc[j].power;
			}
			tmpCharge = max(tmpCharge, chargeA + chargeB);
		}
		tmpCharge = max(tmpCharge, chargeA + chargeB);
	}
	for (int i = 0; i < a; i++)
	{
		int flag = 0;
		if (availableB[i] == 0)
			continue;
		chargeB = bc[i].power;
		for (int j = 0; j < a; j++)
		{
			if (availableA[j] == 0)
				continue;
			if (i == j)
			{
				flag = 1;
				chargeA = bc[i].power / 2;
				chargeB = bc[j].power / 2;
			}
			else
			{
				if (flag)
				{
					chargeB *= 2;
					flag = 0;
				}
				chargeA = bc[j].power;
			}
			tmpCharge = max(tmpCharge, chargeA + chargeB);
		}
		tmpCharge = max(tmpCharge, chargeA + chargeB);
	}
	chargeMax += tmpCharge;
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		cin >> m >> a;
		// A와 B의 이동 경로
		for (int i = 1; i <= m; i++)
			cin >> routeA[i];
		for (int i = 1; i <= m; i++)
			cin >> routeB[i];
		// 충전소 정보 
		for (int i = 0; i < a; i++)
		{
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			bc.push_back({ y, x, c, p });
		}

		int idxA = 0, idxB = 0;
		// 충전 가능한 충전소 찾기(거리 계산) -> 충전기 선택하기 -> 충전량 계산
		for (int nowTime = 0; nowTime <= m; nowTime++)
		{
			memset(availableA, 0, sizeof(availableA));
			memset(availableB, 0, sizeof(availableB));
			availableACnt = 0;
			availableBCnt = 0;
			idxA = routeA[nowTime];
			idxB = routeB[nowTime];
			userA = { userA.y + dy[idxA], userA.x + dx[idxA] };
			userB = { userB.y + dy[idxB], userB.x + dx[idxB] };
			findBC(userA, userB);
			selectAndCalc();
		}

		cout << "#" << test_case << " " << chargeMax << "\n";
	}
	return 0;
}
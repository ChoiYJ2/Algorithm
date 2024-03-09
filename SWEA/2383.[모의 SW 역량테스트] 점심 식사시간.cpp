#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int stairCnt;
int minTime;

struct Stair
{
	int y;
	int x;
	int stairLength;
}stair[2];

struct Person
{
	int y;
	int x;
	int timeInRoom;

	bool operator<(Person a) const
	{
		if (timeInRoom < a.timeInRoom)
			return false;
		if (timeInRoom > a.timeInRoom)
			return true;
		return false;
	}
};

vector<Person> people;
priority_queue<Person> readyToStair[2];

void init()
{
	stairCnt = 0;
	people.clear();
	for (int i = 0; i < 2; i++)
	{
		while(!readyToStair[i].empty())
			readyToStair[i].pop();
	}
	minTime = 0;
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int room;
			cin >> room;
			if (room > 1)
			{
				stair[stairCnt] = { i, j, room };
				stairCnt++;
			}
			else if (room == 1)
				people.push_back({ i, j });
		}
	}
}

void solution()
{
	int minimum = 2134567890;
	for (Person now : people)
	{
		int distA = abs(now.y - stair[0].y) + abs(now.x - stair[0].x);
		int distB = abs(now.y - stair[1].y) + abs(now.x - stair[1].x);
		if (distA > distB)
		{
			now.timeInRoom = distB;
			readyToStair[1].push(now);
			minimum = min(minimum, distB);
		}
		else if (distA < distB)
		{
			now.timeInRoom = distA;
			readyToStair[0].push(now);
			minimum = min(minimum, distA);
		}
		else
		{
			now.timeInRoom = distA;
			minimum = min(minimum, distA);
			if (readyToStair[0].size() < readyToStair[1].size())
				readyToStair[0].push(now);
			else
				readyToStair[1].push(now);
		}
	}

	minTime = minimum;
	priority_queue<int, vector<int>, less<int>> inStair[2];
	while (1)
	{

		if(!readyToStair[0].empty())
		{
			while (inStair[0].size() < 3)
			{
				if (readyToStair[0].empty() || readyToStair[0].top().timeInRoom > minTime)
					break;
				if (minTime >= readyToStair[0].top().timeInRoom)
				{
					inStair[0].push(minTime);
					readyToStair[0].pop();
				}
			}
		}

		if(!readyToStair[1].empty())
		{
			while (inStair[1].size() < 3)
			{
				if (readyToStair[1].empty() || readyToStair[1].top().timeInRoom > minTime)
					break;
				if (minTime >= readyToStair[1].top().timeInRoom)
				{
					inStair[1].push(minTime);
					readyToStair[1].pop();
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (inStair[0].empty())
				break;
			if (minTime == inStair[0].top())
				break;

			int dif = minTime - inStair[0].top();
			if (stair[0].stairLength > dif)
				break;
			else if (dif == stair[0].stairLength)
				inStair[0].pop();
		}

		for (int i = 0; i < 3; i++)
		{
			if (inStair[1].empty())
				break;
			if (minTime == inStair[1].top())
				break;

			int dif = minTime - inStair[1].top();
			if (stair[1].stairLength > dif)
				break;
			else if (dif == stair[1].stairLength)
				inStair[1].pop();
		}
		
		minTime++;
		if (inStair[0].empty() && inStair[1].empty())
			break;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		init();
		input();
		solution();

		cout << "#" << test_case << " " << minTime << "\n";
	}
	return 0;
}

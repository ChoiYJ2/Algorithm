#include <iostream>
#include <cstring>

using namespace std;

int n, ramp_x;
int map[21][21];
int cnt;
int isPlaced[21][21];

void init()
{
	for (int i = 0; i < 21; i++)
		memset(map[i], 0, sizeof(map[i]));
	for (int i = 0; i < 21; i++)
		memset(isPlaced[i], 0, sizeof(isPlaced[i]));
	cnt = 0;
}

void checkVert()
{
	for (int x = 0; x < n; x++)
	{
		int flag = 1;
		for (int y = 1; y < n; y++)
		{
			// 높이 차가 2 이상인 경우
			if (abs(map[y][x] - map[y - 1][x]) >= 2)
			{
				flag = 0;
				break;
			}

			// 경사로 설치해야 하는 경우
			else if (abs(map[y][x] - map[y - 1][x]) == 1)
			{
				// y - 1이 더 낮은 경우
				if (map[y][x] > map[y - 1][x])
				{
					// y - 1이 0인 경우 -> 설치 불가
					if (y - 1 == 0)
					{
						flag = 0;
						break;
					}
					else // y - 1이 0이 아닌 경우
					{
						// 경사로 길이가 맵을 초과하는 경우 -> 설치 불가
						if (y - ramp_x < 0)
						{
							flag = 0;
							break;
						}
						else
						{
							for (int i = 1; i <= ramp_x; i++)
							{
								if (map[y - 1][x] != map[y - i][x])
								{
									flag = 0;
									break;
								}
								if (isPlaced[y - i][x])
								{
									flag = 0;
									break;
								}
								isPlaced[y - i][x] = 1;
							}
						}
					}
				}
				// y가 더 낮은 경우
				else if (map[y][x] < map[y - 1][x])
				{
					// 마지막 위치인 경우 설치 불가
					if (y == n - 1)
					{
						flag = 0;
						break;
					}
					else
					{
						// 경사로 길이가 맵을 초과하는 경우 -> 설치 불가
						if (y + ramp_x - 1 >= n)
						{
							flag = 0;
							break;
						}
						else
						{
							for (int i = 0; i < ramp_x; i++)
							{
								if (map[y][x] != map[y + i][x])
								{
									flag = 0;
									break;
								}
								if (isPlaced[y + i][x])
								{
									flag = 0;
									break;
								}
								isPlaced[y + i][x] = 1;
							}
						}
					}
				}
			}
		}
		if (flag)
			cnt++;
	}
}

void checkHori()
{
	for (int y = 0; y < n; y++)
	{
		int flag = 1;
		for (int x = 1; x < n; x++)
		{
			// 높이 차가 2 이상인 경우
			if (abs(map[y][x] - map[y][x - 1]) >= 2)
			{
				flag = 0;
				break;
			}

			// 경사로 설치해야 하는 경우
			else if (abs(map[y][x] - map[y][x - 1]) == 1)
			{
				// y - 1이 더 낮은 경우
				if (map[y][x] > map[y][x - 1])
				{
					// y - 1이 0인 경우 -> 설치 불가
					if (x - 1 == 0)
					{
						flag = 0;
						break;
					}
					else // y - 1이 0이 아닌 경우
					{
						// 경사로 길이가 맵을 초과하는 경우 -> 설치 불가
						if (x - ramp_x < 0)
						{
							flag = 0;
							break;
						}
						else
						{
							for (int i = 1; i <= ramp_x; i++)
							{
								if (map[y][x - 1] != map[y][x - i])
								{
									flag = 0;
									break;
								}
								if (isPlaced[y][x - i])
								{
									flag = 0;
									break;
								}
								isPlaced[y][x - i] = 1;
							}
						}
					}
				}
				// y가 더 낮은 경우
				else if (map[y][x] < map[y][x - 1])
				{
					// 마지막 위치인 경우 설치 불가
					if (x == n - 1)
					{
						flag = 0;
						break;
					}
					else
					{
						// 경사로 길이가 맵을 초과하는 경우 -> 설치 불가
						if (x + ramp_x - 1 >= n)
						{
							flag = 0;
							break;
						}
						else
						{
							for (int i = 0; i < ramp_x; i++)
							{
								if (map[y][x] != map[y][x + i])
								{
									flag = 0;
									break;
								}
								if (isPlaced[y][x + i])
								{
									flag = 0;
									break;
								}
								isPlaced[y][x + i] = 1;
							}
						}
					}
				}
			}
		}
		if (flag)
			cnt++;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		init();
		cin >> n >> ramp_x;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
		}
		checkVert();
		for (int i = 0; i < 21; i++)
			memset(isPlaced[i], 0, sizeof(isPlaced[i]));
		checkHori();

		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}
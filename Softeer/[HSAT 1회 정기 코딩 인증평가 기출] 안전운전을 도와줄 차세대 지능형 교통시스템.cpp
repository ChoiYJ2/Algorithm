#include <iostream>
#include <queue>

using namespace std;

int n, t;
int trafficLight[101][101][4];
int visited[101][101];
int nowTime = 0;
int moveCar;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

struct Car
{
    int y;
    int x;
    int dir;
};

int trafficSignal[13][3] = { {0, 0, 0}, {0, 1, 3}, {1, 0, 2}, {2, 3, 1}, {3, 2, 0},
                        {0, 1, 4}, {1, 0, 4}, {2, 3, 4}, {3, 2, 4},
                        {0, 4, 3}, {1, 4, 2}, {2, 4, 1}, {3, 4, 0} };

void bfs(int y, int x)
{
    queue<Car> q;
    visited[1][1] = 1;
    q.push({ 1, 1, 2 });
    while (!q.empty())
    {
        Car now = q.front();
        q.pop();
        int nowLightNum = trafficLight[now.y][now.x][nowTime];
        cout << trafficSignal[nowLightNum][0] << "\n";
        cout << now.dir << "\n";
        if (now.dir != trafficSignal[nowLightNum][0])
            continue;

        int nowSignal[3];
        for (int i = 1; i < 3; i++)
            nowSignal[i] = trafficSignal[nowLightNum][i];
        for (int i = 0; i < 2; i++)
        {
            int ny = now.y + dy[nowSignal[i]];
            int nx = now.x + dx[nowSignal[i]];

            if (ny < 1 || nx < 1 || ny > n || nx > n)
                continue;
            if (visited[ny][nx])
                continue;
            moveCar++;
            nowTime++;
        }
    }
}

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            for (int j = 0; j < 4; j++)
                cin >> trafficLight[i][k][j];
        }
    }
    bfs(1, 1);
    cout << moveCar;
    return 0;
}
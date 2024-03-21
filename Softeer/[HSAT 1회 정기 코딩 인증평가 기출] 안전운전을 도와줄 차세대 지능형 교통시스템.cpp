#include <iostream>
#include <queue>

using namespace std;

int n, t;
int trafficSignal[101][101][4];
int visited[101][101];
int moving;
int dy[] = {0, -1, 0, 1, 0};
int dx[] = {1, 0, -1, 0, 0};
int signal[13][3] = {{4, 4, 4},
{0, 1, 3}, {1, 0, 2}, {2, 3, 1}, {3, 2, 0},
{0, 1, 4}, {1, 0, 4}, {2, 3, 4}, {3, 2, 4},
{0, 4, 3}, {1, 4, 2}, {2, 4, 1}, {3, 4, 0}
};

struct Car
{
    int y;
    int x;
    int direction;
    int nowTime;
};

void bfs()
{
    queue<Car> q;
    q.push({1, 1, 1, 0});
    visited[1][1] = 1;
    while(!q.empty())
    {
        Car now = q.front();
        q.pop();
        moving++;
        if(now.nowTime > t)
            return;
        int nowLightSignal = trafficSignal[now.y][now.x][now.nowTime % 4];
        if(now.direction != signal[nowLightSignal][0])
            return;

        int tmpSignal[3];
        for(int i = 0; i < 3; i++)
            tmpSignal[i] = signal[nowLightSignal][i];

        for(int i = 0; i < 3; i++)
        {
            int ny = now.y + dy[tmpSignal[i]];
            int nx = now.x + dx[tmpSignal[i]];

            if(ny < 1 || nx < 1 || ny > n || nx > n)
                continue;
            if(visited[ny][nx])
                continue;
            visited[ny][nx] = 1;
            q.push({ny, nx, tmpSignal[i], now.nowTime + 1});
        }
    }
}

int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 0; k < 4; k++)
                cin >> trafficSignal[i][j][k];
        }
    }

    bfs();

    cout << moving;
    return 0;
}
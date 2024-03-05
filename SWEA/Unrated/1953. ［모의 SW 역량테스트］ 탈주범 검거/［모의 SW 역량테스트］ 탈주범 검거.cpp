#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int r, c, L;
int map[51][51];
int visited[51][51];
int dy[8][4] = {
    {0, 0, 0, 0},
    {-1, 0, 1, 0},
    {-1, 0, 1, 0},
    {0, 0, 0, 0},
    {-1, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {-1, 0, 0, 0}
};
int dx[8][4] = {
    {0, 0, 0, 0},
    {0, -1, 0, 1},
    {0, 0, 0, 0},
    {0, -1, 0, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 1},
    {0, -1, 0, 0},
    {0, -1, 0, 0}
};
int checkPoint;

struct Point
{
    int y;
    int x;
    int tunnelNum;
    int timeToRunaway;
};

void init()
{
    for (int i = 0; i < 51; i++)
    {
        fill(map[i], map[i] + 51, 0);
        fill(visited[i], visited[i] + 51, 0);
    }
    checkPoint = 1;
}

void bfs(int y, int x, int tunnel, int startTime)
{
    queue<Point> q;
    visited[y][x] = 1;
    q.push({ y, x, tunnel, startTime - 1 });
    while (!q.empty())
    {
        Point now = q.front();
        q.pop();
        if (now.timeToRunaway == 0)
            return;
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[now.tunnelNum][i];
            int nx = now.x + dx[now.tunnelNum][i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (visited[ny][nx])
                continue;
            if (map[ny][nx] == 0)
                continue;
            if ((abs(dy[now.tunnelNum][i]) != abs(dy[map[ny][nx]][(i + 2) % 4])) || (abs(dx[now.tunnelNum][i]) != abs(dx[map[ny][nx]][(i + 2) % 4])))
                continue;

            checkPoint++;
            visited[ny][nx] = 1;
            q.push({ ny, nx, map[ny][nx], now.timeToRunaway - 1 });
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();
        cin >> n >> m >> r >> c >> L;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> map[i][j];
        }
        bfs(r, c, map[r][c], L);
        cout << "#" << test_case << " " << checkPoint << "\n";
    }
    return 0;
}
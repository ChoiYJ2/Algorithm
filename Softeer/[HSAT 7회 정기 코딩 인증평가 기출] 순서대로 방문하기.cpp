#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[5][5];
int visited[5][5];
int cnt;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
struct Point
{
    int y;
    int x;
};
vector<Point> goal;

void dfs(int lev, int y, int x)
{
    if (lev == m)
    {
        if (y == goal[lev - 1].y && x == goal[lev - 1].x)
            cnt++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || nx < 1 || ny > n || nx > n)
            continue;
        if (map[ny][nx] || visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        if (ny == goal[lev].y && nx == goal[lev].x)
            dfs(lev + 1, ny, nx);
        else
            dfs(lev, ny, nx);
        visited[ny][nx] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < m; i++)
    {
        int y, x;
        cin >> y >> x;
        goal.push_back({ y, x });
    }
    visited[goal[0].y][goal[0].x] = 1;
    dfs(1, goal[0].y, goal[0].x);
    cout << cnt;
    return 0;
}
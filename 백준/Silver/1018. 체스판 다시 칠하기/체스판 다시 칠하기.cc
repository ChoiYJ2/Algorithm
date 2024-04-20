#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
char board[51][51];
int visited[51][51];
int minChange = 2134567890;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
struct Coord
{
    int y, x;
};

void bfs(int y, int x)
{
    queue<Coord> q;
    q.push({ y, x });
    visited[y][x] = 1;
    int change = 0;
    char subBoard[51][51];
    memset(subBoard, 0, sizeof(subBoard));
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
            subBoard[i][j] = board[i][j];
    }
    while (!q.empty())
    {
        Coord now = q.front();
        q.pop();
        if (now.y >= n || now.x >= m)
            break;
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < y || nx < x || abs(ny - y) >= 8 || abs(nx - x) >= 8)
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx]++;
            if (subBoard[ny][nx] == subBoard[now.y][now.x])
            {
                if (subBoard[now.y][now.x] == 'B')
                    subBoard[ny][nx] = 'W';
                else if (subBoard[now.y][now.x] == 'W')
                    subBoard[ny][nx] = 'B';
                change++;
            }
            q.push({ ny, nx });
        }
    }
    minChange = min(minChange, change);

    memset(subBoard, 0, sizeof(subBoard));
    memset(visited, 0, sizeof(visited));
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
            subBoard[i][j] = board[i][j];
    }
    change = 1;
    if (subBoard[y][x] == 'B')
        subBoard[y][x] = 'W';
    else if (subBoard[y][x] == 'W')
        subBoard[y][x] = 'B';
    q.push({ y, x });
    while (!q.empty())
    {
        Coord now = q.front();
        q.pop();
        if (now.y >= n || now.x >= m)
            break;
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < y || nx < x || abs(ny - y) >= 8 || abs(nx - x) >= 8)
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx]++;
            if (subBoard[ny][nx] == subBoard[now.y][now.x])
            {
                if (subBoard[now.y][now.x] == 'B')
                    subBoard[ny][nx] = 'W';
                else if (subBoard[now.y][now.x] == 'W')
                    subBoard[ny][nx] = 'B';
                change++;
            }
            q.push({ ny, nx });
        }
    }
    minChange = min(minChange, change);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (y + 7 >= n || x + 7 >= m)
                break;
            memset(visited, 0, sizeof(visited));
            bfs(y, x);
        }
    }

    cout << minChange;
    return 0;
}
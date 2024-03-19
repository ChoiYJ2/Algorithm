#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int n, m;
int map[5][5];
int visited[5][5];
int cnt;

struct Point{
    int y;
    int x;
    int flag;
};

vector<Point> goal;

void bfs(int y, int x)
{
    queue<Point> q;
    q.push({y, x, 0});
    visited[y][x] = 1;
    while(!q.empty())
    {
        Point now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if(ny < 1 || nx < 1 || ny > n || nx > n)
                continue;
            if(map[ny][nx] == 1)
                continue;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];
    }

    for(int i = 0; i < m; i++)
    {
        int y, x;
        cin >> y >> x;
        goal.push_back({y, x, 0});
    }

    bfs(goal[0].y, goal[0].x);
    
    cout << cnt;
    return 0;
}

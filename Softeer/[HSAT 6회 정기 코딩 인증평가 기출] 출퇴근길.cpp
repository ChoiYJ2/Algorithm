#include <iostream>
#include <vector>

using namespace std;

int n, m, s, t;
vector<int> road[100001];
int homeTocompany[100001];
int dat[100001];
int cnt;

void dfs(int start, int end, int now)
{
    if(now == end)
    {
        for(int i = 1; i <= n; i++)
        {
            if(end == t && dat[i])
            {
                if(homeTocompany[i])
                    continue;
                homeTocompany[i] = 1;
                dat[i] = 0;
            }
            else if(end != t && homeTocompany[i] && dat[i])
            {
                homeTocompany[i] = 0;
                dat[i] = 0;
                cnt++;
            } 
        }
        return;
    }
    for(int i = 0; i < road[now].size(); i++)
    {
        if(dat[road[now][i]])
            continue;
        if(road[now][i] != start && road[now][i] != end)
            dat[road[now][i]] = 1;
        dfs(start, end, road[now][i]);
        dat[road[now][i]] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        road[from].push_back(to);
    }
    cin >> s >> t;

    dfs(s, t, s);
    dfs(t, s, t);

    cout << cnt;
    return 0;
}
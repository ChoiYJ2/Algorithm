#include <iostream>
  
using namespace std;
  
int n, b;
int height[21];
int minHeight;
  
void init()
{
    minHeight = 213456890;
    fill(height, height + 21, 0);
}
  
void dfs(int nowHeight, int idx)
{
    if (nowHeight >= b)
    {
        minHeight = min(minHeight, nowHeight);
        return;
    }
  
    for (int i = idx; i < n; i++)
        dfs(nowHeight + height[i], i + 1);
}
  
int main()
{
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();
        cin >> n >> b;
        for (int i = 0; i < n; i++)
            cin >> height[i];
        dfs(0, 0);
  
        cout << "#" << test_case << " " << minHeight - b << "\n";
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int personRank[4][100001];
int scores[4][100001];

void calcRanks(int contestNum)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(scores[contestNum][i] > scores[contestNum][j])
                personRank[contestNum][j]++;
            else if(scores[contestNum][i] < scores[contestNum][j])
                personRank[contestNum][i]++;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> scores[i][j];
            scores[3][j] += scores[i][j];
        }
    }
    
    for(int i = 0; i < 4; i++)
        fill(personRank[i], personRank[i] + n, 1);
    
    for(int i = 0; i < 4; i++)
        calcRanks(i);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < n; j++)
            cout << personRank[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
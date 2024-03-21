#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct ContestScore
{
    int score;
    int personNum;

    bool operator<(ContestScore a) const
    {
        if(score > a.score)
            return true;
        if(score < a.score)
            return false;
        return false;
    }
};
vector<ContestScore> scores(100001);
vector<ContestScore> totalScores(100001);
int ContestRank[100001];

void calcRanks(vector<ContestScore>& nowScore)
{
    int prevScore = -1;
    int prevRank = 0;
    for(int i = 0; i < n; i++)
    {
        if(nowScore[i].score == prevScore)
            ContestRank[nowScore[i].personNum] = prevRank;
        else
            ContestRank[nowScore[i].personNum] = i + 1;
        prevRank = ContestRank[nowScore[i].personNum];
        prevScore = nowScore[i].score;
    }
}

int main()
{
    cin >> n;
    for(int contest = 0; contest < 3; contest++)
    {
        for(int i = 0; i < n; i++)
        {
            int s;
            cin >> s;
            scores[i] = {s, i};
            totalScores[i] = {totalScores[i].score + s, i};
        }

        sort(scores.begin(), scores.begin() + n);
        calcRanks(scores);

        for(int i = 0; i < n; i++)
            cout << ContestRank[i] << " ";
        cout << "\n";
    }

    sort(totalScores.begin(), totalScores.begin() + n);
    calcRanks(totalScores);

    for(int i = 0; i < n; i++)
            cout << ContestRank[i] << " ";
    return 0;
}
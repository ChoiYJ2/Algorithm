#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, int> wordCnt;
struct Words
{
	string word;
	int len, cnt;

	bool operator<(Words a) const
	{
		if (cnt > a.cnt)
			return false;
		if (cnt < a.cnt)
			return true;
		if (len > a.len)
			return false;
		if (len < a.len)
			return true;
		if (word < a.word)
			return false;
		if (word > a.word)
			return true;
		return false;
	}
};
priority_queue<Words> pq;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int s_len = s.length();
		if (s_len < m)
			continue;
		if (wordCnt.count(s) == 0)
			wordCnt.insert({ s, 1 });
		else
			wordCnt[s]++;
		pq.push({ s, s_len, wordCnt[s]});
	}
	while (!pq.empty())
	{
		string now = pq.top().word;
		pq.pop();
		if (wordCnt[now] == -1)
			continue;
		cout << now << "\n";
		wordCnt[now] = -1;
	}
	return 0;
}
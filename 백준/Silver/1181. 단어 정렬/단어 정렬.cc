#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	if (a.size() < b.size())
		return true;
	if (a.size() > b.size())
		return false;
	if (a < b)
		return true;
	if (a > b)
		return false;
	return false;
}

int n;
vector<string> words;

int main()
{
	unordered_map<string, int> dat;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		if (dat.find(word) != dat.end())
			continue;
		dat.insert({ word, 1 });
		words.push_back(word);
	}

	sort(words.begin(), words.end(), cmp);

	for (int i = 0; i < words.size(); i++)
		cout << words[i] << "\n";
	return 0;
}
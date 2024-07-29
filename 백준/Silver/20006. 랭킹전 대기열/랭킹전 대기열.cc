#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RoomInfo
{
	int minLev, maxLev;
	bool isFull;
	vector<pair<string, int>> players;
};

vector<RoomInfo> rooms;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int p, m;
	cin >> p >> m;
	for(int i =0; i < p; i++)
	{
		int l;
		string n;
		cin >> l >> n;
		if (rooms.size() == 0)
		{
			RoomInfo newInfo = { l - 10, l + 10, false };
			newInfo.players.push_back({n, l});
			if (newInfo.players.size() == m)
				newInfo.isFull = true;
			rooms.push_back(newInfo);
		}
		else
		{
			int flag = 0;
			for (int idx =0; idx < rooms.size(); idx++)
			{
				RoomInfo now = rooms[idx];
				if (now.isFull)
					continue;
				if (now.minLev <= l && l <= now.maxLev)
				{
					rooms[idx].players.push_back({ n, l });
					if (rooms[idx].players.size() == m)
						rooms[idx].isFull = true;
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				RoomInfo newInfo = { l - 10, l + 10, false };
				newInfo.players.push_back({ n, l });
				if (newInfo.players.size() == m)
					newInfo.isFull = true;
				rooms.push_back(newInfo);
			}
		}
	}
	for (RoomInfo& now : rooms)
	{
		
		sort(now.players.begin(), now.players.end());
		if (now.isFull)
			cout << "Started!\n";
		else
			cout << "Waiting!\n";
		for (int i = 0; i < now.players.size(); i++)
			cout << now.players[i].second << " " << now.players[i].first << "\n";
	}
	return 0;
}
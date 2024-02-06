#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
int t_len;
int flag;

string add_A(string str)
{
	return str + 'A';
}

string add_B(string str)
{
	str += 'B';
	reverse(str.begin(), str.end());
	return str;
}

void dfs(int len, string now_str)
{
	if (len == t_len)
	{
		if (now_str == t)
			flag = 1;
		return;
	}
	for (int i = 0; i <= (t_len - len); i++)
	{
		string com_s = t.substr(i, len);
		if (com_s != now_str)
			flag = -1;
		else
		{
			flag = 0;
			break;
		}
	}
	if(flag == -1)
	{
		string reverse_now = now_str;
		reverse(reverse_now.begin(), reverse_now.end());
		for (int i = 0; i <= (t_len - len); i++)
		{
			string com_s = t.substr(i, len);
			if (com_s != reverse_now)
				flag = -1;
			else
			{
				flag = 0;
				break;
			}
		}
	}
	if ((flag == 1) || (flag == -1))
		return;
	dfs(len + 1, add_A(now_str));
	if (flag == 1)
		return;
	dfs(len + 1, add_B(now_str));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	cin >> t;
	t_len = t.length();
	dfs(s.length(), s);
	if (flag == -1)
		flag = 0;
	cout << flag;
	return 0;
}
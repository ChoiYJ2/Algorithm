#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

priority_queue<int> passwords;
int n, k;
int pw_length;
string pw;
vector<string> DAT;

int hexStr_to_dec(string str)
{
	int res_dec = 0;
	for (int i = 0; i < pw_length; i++)
	{
		if ('A' <= str[i] && str[i] <= 'F')
			res_dec += (str[i] - 'A' + 10) * pow(16, pw_length - i - 1);
		else if ('0' <= str[i] && str[i] <= '9')
			res_dec += (str[i] - '0') * pow(16, pw_length - i - 1);
	}
	return res_dec;
}

void print_dec()
{
	for (int i = 0; i < k - 1; i++)
		passwords.pop();
	cout << passwords.top() << "\n";
	return;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		passwords = priority_queue<int>();
		DAT.clear();
		cin >> n >> k;
		pw_length = n / 4;
		cin >> pw;
		for (int i = 0; i < pw_length; i++)
		{
			for (int j = 0; j < n; j += pw_length)
			{
				string split_pw;
				for (int k = 0; k < pw_length; k++)
				{
					int idx = (i + j + k) % n;
					split_pw += pw[idx];
				}
				if (!DAT.empty() && find(DAT.begin(), DAT.end(), split_pw) != DAT.end())
					continue;
				else
				{
					int dec = hexStr_to_dec(split_pw);
					DAT.push_back(split_pw);
					passwords.push(dec);
				}
			}
		}
		cout << "#" << test_case << " ";
		print_dec();
	}
	return 0;
}

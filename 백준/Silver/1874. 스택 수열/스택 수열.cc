#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> stack;
	vector<int> numList(100001);
	vector<char> operation;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		numList[i] = num;
	}

	int idx = 0;
	int now = 1;
	while (idx < n)
	{
		if (numList[idx] >= now)
		{
			stack.push_back(now);
			now++;
			operation.push_back('+');
		}
		else if (numList[idx] < now)
		{
			if (stack[stack.size() - 1] == numList[idx])
			{
				idx++;
				operation.push_back('-');
				stack.pop_back();
			}
			else
			{
				cout << "NO";
				break;
			}
		}
	}
	if (idx == n)
	{
		for (int i = 0; i < operation.size(); i++)
			cout << operation[i] << "\n";
	}
	return 0;
}
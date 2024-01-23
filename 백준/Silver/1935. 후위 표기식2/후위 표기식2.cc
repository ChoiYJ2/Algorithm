#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n;
	string calc;
	stack<double> nums_stack;
	double nums[26] = { 0 };
	double res = 0;
	cin >> n;
	cin >> calc;
	for (int i = 0; i < calc.length(); i++)
	{
		if ('A' <= calc[i] && calc[i] <= 'Z' && nums[calc[i] - 'A'] == 0)
			cin >> nums[calc[i] - 'A'];
	}
	for (int i = 0; i < calc.length(); i++)
	{
		if ('A' <= calc[i] && calc[i] <= 'Z')
			nums_stack.push(nums[calc[i] - 'A']);
		else
		{
			double a = nums_stack.top();
			nums_stack.pop();
			double b = nums_stack.top();
			nums_stack.pop();
			if (calc[i] == '*')
			{
				res = b * a;
				nums_stack.push(res);
			}
			else if (calc[i] == '/')
			{
				res = b / a;
				nums_stack.push(res);
			}
			else if (calc[i] == '+')
			{
				res = b + a;
				nums_stack.push(res);
			}
			else if (calc[i] == '-')
			{
				res = b - a;
				nums_stack.push(res);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << res;
	return 0;
}
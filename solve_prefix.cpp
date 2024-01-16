#include <iostream>
#include <string>
#include <stack>
using namespace std;


int performOperation(int a, int b, char op)
{
	int ans = 0;
	if (op == '*')
	{
		ans = a * b;
	}
	else if (op == '/')
	{
		if (b != 0)
			ans = a / b;
	}
	else if (op == '+')
	{
		ans = a + b;
	}
	else if (op == '-')
	{
		ans = a - b;
	}
	return ans;
}


int solvePrefix(string str)
{
	stack<int> s;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			s.push(str[i] - '0');
		}
		else
		{
			int first = s.top();
			s.pop();
			int second = s.top();
			s.pop();
			s.push(performOperation(first, second, str[i]));
		}
	}
	return s.top();
}

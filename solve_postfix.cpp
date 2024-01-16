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



int solvePostfix(string str)
{
	stack<int> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			s.push(str[i] - '0');
		}
		else
		{
			int second = s.top();
			s.pop();
			int first = s.top();
			s.pop();
			s.push(performOperation(first, second, str[i]));
		}
	}
	return s.top();

}

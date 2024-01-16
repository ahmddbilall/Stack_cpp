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



int solveInfix(string str)
{
	stack<int> operands;
	stack<char>operators;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int operand = 0;
			while (i < str.size() && str[i] >= '0' && str[i] <= '9')
			{
				operand *= 10;
				operand += str[i] - '0';
				i++;
			}
			operands.push(operand);
			i--;
		}
		else if (str[i] == '(')
		{
			operators.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (operators.top() != '(')
			{
				char op = operators.top();
				operators.pop();
				int second = operands.top();
				operands.pop();
				int first = operands.top();
				operands.pop();
				operands.push(performOperation(first, second, op));
			}
			operators.pop();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			if (!operators.empty()) {
				if (operators.top() == '*' || operators.top() == '/')
				{
					char op = operators.top();
					operators.pop();
					int second = operands.top();
					operands.pop();
					int first = operands.top();
					operands.pop();
					operands.push(performOperation(first, second, op));
				}
			}
			operators.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!operators.empty() && (operators.top() == '*' || operators.top() == '/'))
			{
				char op = operators.top();
				operators.pop();
				int second = operands.top();
				operands.pop();
				int first = operands.top();
				operands.pop();
				operands.push(performOperation(first, second, op));
			}
			operators.push(str[i]);

		}
	}

	while (!operators.empty())
	{
		char op = operators.top();
		operators.pop();
		int second = operands.top();
		operands.pop();
		int first = operands.top();
		operands.pop();
		operands.push(performOperation(first, second, op));
	}
	if (operands.empty())
		return 0;
	int ans = operands.top();
	operands.pop();
	return ans;
}

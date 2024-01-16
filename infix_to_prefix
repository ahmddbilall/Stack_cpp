#include <iostream>
#include <string>
#include <stack>
using namespace std;


string InfixtoPrefix(string str)
{
	stack<char> operation;
	stack<string> pre;

	for (int i = 0; i < str.size(); i++)
	{

		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			string operand = "";
			while (i < str.size() && (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			{
				operand += str[i];
				i++;
			}
			i--;
			pre.push(operand);
		}
		else if (str[i] == '(')
		{
			operation.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (!operation.empty() && operation.top() != '(')
			{
				string first = pre.top();
				pre.pop();
				string second = pre.top();
				pre.pop();

				pre.push(operation.top() + second + first);
				operation.pop();
			}
			operation.pop();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!operation.empty() && (operation.top() == '*' || operation.top() == '/'))
			{
				string first = pre.top();
				pre.pop();
				string second = pre.top();
				pre.pop();

				pre.push(operation.top() + second + first);
				operation.pop();
			}
			operation.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!operation.empty() && (operation.top() == '*' || operation.top() == '/'))
			{
				string first = pre.top();
				pre.pop();
				string second = pre.top();
				pre.pop();

				pre.push(operation.top() + second + first);
				operation.pop();
			}
			operation.push(str[i]);
		}
	}

	while (!operation.empty())
	{
		string first = pre.top();
		pre.pop();
		string second = pre.top();
		pre.pop();

		pre.push(operation.top() + second + first);
		operation.pop();
	}
	string answer = pre.top();
	pre.pop();
	return answer;
}

#include <iostream>
#include <string>
#include <stack>
using namespace std;


string InfixtoPostfix(string str)
{
	stack<char> operation;
	stack<string> post;

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
			post.push(operand);
		}
		else if (str[i] == '(')
		{
			operation.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (!operation.empty() && operation.top() != '(')
			{
				string first = post.top();
				post.pop();
				string second = post.top();
				post.pop();

				post.push(second + first + operation.top());
				operation.pop();
			}
			operation.pop();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!operation.empty() && (operation.top() == '*' || operation.top() == '/'))
			{
				string first = post.top();
				post.pop();
				string second = post.top();
				post.pop();

				post.push(second + first + operation.top());
				operation.pop();
			}
			operation.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!operation.empty() && (operation.top() == '*' || operation.top() == '/'))
			{
				string first = post.top();
				post.pop();
				string second = post.top();
				post.pop();

				post.push(second + first + operation.top());
				operation.pop();
			}
			operation.push(str[i]);
		}
	}

	while (!operation.empty())
	{
		string first = post.top();
		post.pop();
		string second = post.top();
		post.pop();

		post.push(second + first + operation.top());
		operation.pop();
	}
	string answer = post.top();
	post.pop();
	return answer;
}

#include <iostream>
#include <string>
#include <stack>

bool isValid(const std::string& expression)
{
    std::stack<char> brackets;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (brackets.empty())
            {
                return false;
            }

            char top = brackets.top();
            brackets.pop();

            if (ch == ')' && top != '(')
                return false;

            if (ch == ']' && top != '[')
                return false;

            if (ch == '}' && top != '{')
                return false;
        }
    }

    return brackets.empty();
}

int main()
{
    std::string expression;

    while (true)
    {
        std::cout << "Enter expression (exit to stop):\n";
        std::getline(std::cin, expression);

        if (expression == "exit")
        {
            break;
        }

        if (isValid(expression))
        {
            std::cout << "Correct\n";
        }
        else
        {
            std::cout << "Error\n";
        }
    }
}
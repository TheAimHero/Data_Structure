#include <iostream>
#include <stack>
#include <string>
void check_parenthesis(std::string a)
{
    std::stack<int> s;
    int i = 0;
    while (i < a.length())
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            s.push(a[i]);
            i++;
        }
        else if ((a[i] - s.top()) == 2 || (a[i] - s.top()) == 1)
        {
            if (!(s.empty()))
            {
                std::cout << "The parenthesis are not correct." << std::endl;
                return;
            }
            s.pop();
            i++;
        }
        else
        {
            i++;
        }
    }
    if (s.empty())
    {
        std::cout << "The parenthesis are correct." << std::endl;
    }
    else
    {
        std::cout << "The parenthesis are not correct." << std::endl;
    }
}
int main()
{
    std::string s = "{[(a+b)*(a-b)]}}";
    // std::string s = "vedant";
    check_parenthesis(s);
    return 0;
}

#include <bits/stdc++.h>

class Infix_To_Postfix
{
public:
    int is_operator(char a);
    int precedence(char a);
    void empty_until(std::stack<char> &s, std::string &postfix);
    std::string Postfix(std::string &infix);
    int is_braces(char a);
    std::string Prefix(std::string infix);
};

int Infix_To_Postfix::is_operator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == '^')
    {
        return 1;
    }
    return 0;
}

int Infix_To_Postfix::precedence(char a)
{

    if (a == '+' || a == '-')
    {
        return 1;
    }

    else if (a == '*' || a == '/')
    {
        return 2;
    }
    if (a == '^')
    {
        return 3;
    }
    else if (a == '(')
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

void Infix_To_Postfix::empty_until(std::stack<char> &s, std::string &postfix)
{
    while (s.top() != '(')
    {
        postfix.push_back(s.top());
        s.pop();
    }
    s.pop();
}

int Infix_To_Postfix::is_braces(char a)
{
    if (a == ')')
    {
        return 1;
    }
    return 0;
}

std::string Infix_To_Postfix::Postfix(std::string &infix)
{
    int i;
    i = 0;
    std::stack<char> s;
    s.push(' ');
    std::string postfix;
    while (i < infix.size())
    {
        if (is_braces(infix[i]))
        {
            empty_until(s, postfix);
            i++;
        }

        else if (!(is_operator(infix[i])))
        {
            postfix.push_back(infix[i]);
            i++;
        }

        else
        {
            if (precedence(infix[i]) > precedence(s.top()))
            {
                s.push(infix[i]);
                i++;
            }
            else
            {
                if (s.top() == '(')
                {
                    s.push(infix[i]);
                    i++;
                }
                else
                {
                    postfix.push_back(s.top());
                    s.pop();
                }
            }
        }
    }
    while (!(s.empty()))
    {
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}

std::string Infix_To_Postfix::Prefix(std::string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
            continue;
        }
        if (infix[i] == ')')
        {
            infix[i] = '(';
            continue;
        }
    }
    infix = Postfix(infix);
    reverse(infix.begin(), infix.end());
    return infix;
}

int main()
{
    std::string s = "a^b*c-c+d/a/e+e";
    Infix_To_Postfix a;
    std::cout << a.Prefix(s);
    return 0;
}

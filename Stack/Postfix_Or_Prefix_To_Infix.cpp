#include <bits/stdc++.h>

using namespace std;

class Postfix_Or_Prefix_To_Infix
{
public:
    string Postfix_To_Infix(string &postfix);
    string Prefix_To_Infix(string &prefix);
    int is_operator(char s);
};

string Postfix_Or_Prefix_To_Infix::Postfix_To_Infix(string &postfix)
{
    stack<string> s;
    string infix;
    int i = 0;
    while (i < postfix.length())
    {
        if (!(is_operator(postfix[i])))
        {
            string str;
            str += postfix[i];
            s.push(str);
            i++;
        }
        else
        {
            string top_1 = s.top();
            s.pop();
            string top_2 = s.top();
            s.pop();
            string str;
            str += (top_1 + postfix[i] + top_2);
            s.push(str);
            i++;
        }
    }
    infix = s.top();
    reverse(infix.begin(), infix.end());
    return infix;
}

int Postfix_Or_Prefix_To_Infix::is_operator(char s)
{
    if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^')
    {
        return 1;
    }
    return 0;
}

string Postfix_Or_Prefix_To_Infix::Prefix_To_Infix(string &prefix)
{
    reverse(prefix.begin(), prefix.end());
    prefix = Postfix_To_Infix(prefix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    Postfix_Or_Prefix_To_Infix a;
    string s = "-*^abc+c+/d/aee";
    // getline(cin, s);
    cout << a.Prefix_To_Infix(s);
    return 0;
}
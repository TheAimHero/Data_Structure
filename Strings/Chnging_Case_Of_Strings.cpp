
#include <bits/stdc++.h>
using namespace std;

void toggleChars(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 41 && str[i] <= 90)
            str[i] = str[i] + 32;
        else if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }
}
int main()
{
    char str[] = "VEDant";
    toggleChars(str);
    cout << str;
    return 0;
}

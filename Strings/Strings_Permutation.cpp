#include <iostream>
using namespace std;
void perm(char s[], int k)
{
    static char r[5];
    static int h[5] = {};
    if (s[k] == '\0')
    {
        r[k] = '\0';
        for (int i = 0; r[i] != '\0'; i++)
        {
            cout << r[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (h[i] == 0)
            {
                r[k] = s[i];
                h[i] = 1;
                perm(s, k + 1);
                h[i] = 0;
            }
        }
    }
}
int main()
{
    char s[] = "ABC";
    perm(s, 0);
    return 0;
}
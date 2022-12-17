#include <iostream>
using namespace std;
int length_string(char string[])
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}
int main()
{
    char A[] = "Vedant";
    cout << length_string(A);
    return 0;
}
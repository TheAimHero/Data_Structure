#include <iostream>
using namespace std;
int calc(int a[], int i1, int i2)
{
    int i, j;
    i = i1;
    j = i2;
    int r = 0;
    while (i <= j)
    {
        r += a[i];
        i++;
    }
    return r;
}
int *sum(int *array, int size, int sum)
{
    static int total = 0;
    static int i, j;
    i = 0;
    j = 1;
    while (i < size && j < size)
    {
        if (total == sum)
        {
            int *result = new int[2];
            result[0] = i + 1;
            result[1] = j + 1;
            return result;
        }
        else if (total < sum)
        {
            j++;
            total = calc(array, i, j);
        }
        else if (total > sum)
        {
            i++;
            total = calc(array, i, j);
        }
    }
}
int main()
{
    int *arr = new int[10]{11, 23, 25, 29, 43, 48, 51, 52, 58, 67};
    int *b = sum(arr, 10, 168); // enter array ,size of array,enter sum to find
    cout << b[0] << " " << b[1];
    return 0;
}
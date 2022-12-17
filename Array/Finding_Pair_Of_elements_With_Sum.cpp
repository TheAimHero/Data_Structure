#include <iostream>
using namespace std;
struct Array
{
    int length, size, *A;
};
int max(Array array)
{
    int max = array.A[0];
    for (int i = 1; i < array.length; i++)
    {
        if (max < array.A[i])
        {
            max = array.A[i];
        }
    }
    return max;
}
void find_pair(Array array, int value)
{
    int t = max(array) + 1;
    Array *array1 = new Array[t];
    array1->A = new int[t]{};
    array1->length = t;
    array1->size = t;
    for (int i = 0; i < array.length; i++)
    {
        if (array1->A[value - array.A[i]] == 1)
        {
            if (value - array.A[i] < 0)
            {
                continue;
            }
            cout << array.A[i] << " + " << value - array.A[i] << " = " << value << " is required pair." << endl;
        }

        array1->A[array.A[i]]++;
    }
}
int main()
{
    Array arr;
    arr.A = new int[10]{6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    arr.length = 10;
    arr.size = 10;
    find_pair(arr, 10);
    return 0;
}
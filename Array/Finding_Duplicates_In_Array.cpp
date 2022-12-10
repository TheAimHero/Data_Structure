#include <iostream>
using namespace std;
struct Array
{
    int size, length;
    int *A;
};
int max(Array *array)
{
    int max = array->A[0];
    for (int i = 1; i < array->length; i++)
    {
        if (max < array->A[i])
        {
            max = array->A[i];
        }
    }
    return max;
}
void finding_duplicate(Array array)
{
    int t = max(&array) + 1;
    Array *array1 = new Array[t];
    array1->A = new int[t]{};
    for (int i = 0; i < array.length; i++)
    {
        array1->A[array.A[i]]++;
    }
    for (int i = 0; i < t; i++)
    {
        if (array1->A[i] > 1)
        {
            cout << i << " is duplicated for " << array1->A[i] << " times." << endl;
        }
    }
}
int main()
{
    Array arr;
    arr.A = new int[10]{3, 32, 8, 8, 10, 32, 15, 15, 15, 32};
    arr.length = 10;
    arr.size = 10;
    finding_duplicate(arr);
    return 0;
}
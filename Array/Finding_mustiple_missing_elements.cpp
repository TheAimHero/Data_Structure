#include <iostream>
using namespace std;
struct Array
{
    int size, length;
    int A[11];
};
int missing(Array *array)
{
    int difference = array->A[0];
    for (int i = 0; i < array->length; i++)
    {
        if (array->A[i] - i != difference)
        {
            while (difference < array->A[i] - i)
            {
                cout << i + difference << " ";
                difference++;
            }
        }
    }
}
int main()
{
    Array arr = {11, 11, {6, 7, 8, 9, 11, 12, 16, 17, 18, 19, 20}};
    missing(&arr);
    return 0;
}
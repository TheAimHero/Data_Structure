#include <iostream>
#include <cmath>
using namespace std;
struct Array
{
    int size;
    int length;
    int A[10];
};
void display(Array *array)
{
    cout << "The elements of the array are --->  ";
    for (int i = 0; i < array->length; i++)
    {
        cout << array->A[i] << " ";
    }
}
void append(Array *array, int value)
{
    if (array->length < array->size)
    {
        array->A[array->length] = value;
        array->length++;
    }
}
void insert(Array *array, int index, int value)
{
    if (((array->length) != (array->size)) && (index >= 0) && (index <= (array->length)))
    {
        for (int i = array->length; i > index; i--)
        {
            array->A[i] = array->A[i - 1];
        }
        array->A[index] = value;
        array->length++;
    }
}
void remove(Array *array, int index)
{
    if (index >= 0 && index <= array->length)
    {
        for (int i = index; i < (array->length - 1); i++)
        {
            array->A[i] = array->A[i + 1];
        }
        array->length--;
    }
}
int L_search(Array *array, int value)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->A[i] == value)
        {
            swap(array->A[i], array->A[0]);
            return 0;
        }
    }
    return -1;
}
int B_search(Array *array, int value)
{
    int low = 0, high = (array->length - 1), mid = 0;
    while (low <= high)
    {
        mid = floor(((high + low) / 2));
        if (array->A[mid] < value)
        {
            low = 1 + mid;
        }
        else if (array->A[mid] > value)
        {
            high = mid - 1;
        }
        else if (array->A[mid] == value)
        {
            return mid;
        }
    }
    return -1;
}
int get(Array *array, int index)
{
    if (index >= 0 && index < array->length)
    {
        return array->A[index];
    }
}
void set(Array *array, int index, int value)
{
    if (index >= 0 && index < array->length)
    {
        array->A[index] = value;
    }
}
int max(Array *array)
{
    int max = array->A[0];
    for (int i = 1; i < array->length; i++)
    {
        {
            if (max < array->A[i])
            {
                max = array->A[i];
            }
        }
    }
    return max;
}
int min(Array *array)
{
    int min = array->A[0];
    for (int i = 1; i < array->length; i++)
    {
        {
            if (min > array->A[i])
            {
                min = array->A[i];
            }
        }
    }
    return min;
}
int sum(Array *array)
{
    int sum = 0;
    for (int i = 0; i < array->length; i++)
    {
        sum += array->A[i];
    }
    return sum;
}
float avg(Array *array)
{
    float total = sum(array) / array->length;
    return total;
}
void Aux_reverse(Array *array)
{
    int *B = new int[array->length];
    for (int i = (array->length - 1), j = 0; i >= 0;)
    {
        B[j] = array->A[i];
        i--;
        j++;
    }
    for (int i = 0; i < array->length;)
    {
        array->A[i] = B[i];
        i++;
    }
}
void Edge_reverse(Array *array)
{
    for (int i = 0, j = (array->length - 1); i < j;)
    {
        int temp = array->A[i];
        array->A[i] = array->A[j];
        array->A[j] = temp;
        i++;
        j--;
    }
}
void L_shift(Array *array)
{
    for (int i = 0; i < array->length; i++)
    {
        array->A[i] = array->A[i + 1];
    }
}
void L_rotate(Array *array)
{
    int temp = array->A[0];
    for (int i = 0; i < array->length; i++)
    {
        array->A[i] = array->A[i + 1];
    }
    array->A[array->length - 1] = temp;
}
void sorted_insert(Array *array, int value)
{
    for (int i = array->length - 1; i >= 0; i--)
    {
        array->A[i + 1] = array->A[i];
        if (array->A[i - 1] < value)
        {
            array->A[i] = value;
            break;
        }
    }
    array->length++;
}
int check_sorted(Array *array)
{
    for (int i = 1; i < array->length; i++)
    {
        if (array->A[i] < array->A[i - 1])
        {
            return -1;
        }
    }
    return 1;
}
void rearrange(Array *array)
{
    int i = 0, j = array->length - 1;
    while (i < j)
    {
        while (array->A[i] < 0)
        {
            i++;
        }
        while (array->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(array->A[i], array->A[j]);
        }
    }
}
Array *merge(Array *array1, Array *array2)
{
    int t = array1->length + array2->length;
    Array *array3 = new Array[t];
    array3->length = t, array3->size = 30;
    int i = 0, j = 0, k = 0;
    while ((i < array1->length) && (j < array2->length))
    {
        if (array1->A[i] < array2->A[j])
        {
            array3->A[k] = array1->A[i];
            i++;
            k++;
        }
        if (array1->A[i] > array2->A[j])
        {
            array3->A[k] = array2->A[j];
            j++;
            k++;
        }
        if (array1->A[i] == array2->A[j])
        {
            array3->A[k] = array2->A[j];
            j++;
            i++;
            k++;
        }
    }
    for (; i < array1->length; i++)
    {
        array3->A[k] = array1->A[i];
        k++;
    }
    for (; j < array2->length; j++)
    {
        array3->A[k] = array2->A[j];
        k++;
    }
    return array3;
}
int main()
{
    // Array arr = {10, 10, {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}};
    Array arr1;
    Array arr1 = {10, 8, {3, 9, 15, 21, 27, 33, 57, 93}};
    remove(arr1, 9);

    return 0;
}
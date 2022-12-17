#include <iostream>
#include <cmath>
using namespace std;
struct Array
{
    int size;
    int length;
    int *A;
};
void start(Array *array)
{  
    int s, l;
    cout << "Enter the size of the array ---> " << endl;
    cin >> s;
    array->size = s;
    cout << "Enter the length of the array ---> " << endl;
    cin >> l;
    array->length = l;
    array->A = new int[s];
    for (int i = 0; i < l; i++)
    {
        int value = 0;
        cout << "Enter the value of the element at index --> " << i << endl;
        cin >> value;
        array->A[i] = value;
    }
}
void display(Array *array)
{
    cout << "The elements of the array are --->  ";
    for (int i = 0; i < array->length; i++)
    {
        cout << array->A[i] << " ";
    }
}
int L_search(Array *array, int value)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->A[i] == value)
        {
            return 1;
        }
    }
    return -1;
}
// union of two sorted arrays
Array *sorted_union(Array *array1, Array *array2)
{
    int t = array1->length + array2->length;
    Array *array3 = new Array[t];
    array3->length = t, array3->size = 30;
    array3->A = new int[30];
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
// union of two unsorted arrays
Array *unsorted_union(Array *array1, Array *array2)
{
    int t = array1->length + array2->length;
    Array *array3 = new Array[t];
    array3->length = t;
    array3->size = 30;
    array3->A = new int[30];
    int i, j, k;
    i = j = k = 0;
    for (; i < array1->length; i++)
    {
        array3->A[k] = array1->A[i];
        k++;
    }
    for (; j < array2->length; j++)
    {
        int v = L_search(array1, array2->A[j]);
        if (v != 1)
        {
            array3->A[k] = array2->A[j];
            k++;
        }
    }
    return array3;
}
// intersection of two unsorted arrays
Array *unsorted_intersection(Array *array1, Array *array2)
{
    Array *array3 = new Array[array1->length];
    array3->length = 0;
    array3->size = 30;
    array3->A = new int[30];
    int k = 0;
    for (int i = 0; i < array1->length; i++)
    {
        int v = L_search(array2, array1->A[i]);
        if (v == 1)
        {
            array3->A[k] = array1->A[i];
            k++;
            array3->length++;
        }
    }
    return array3;
}
// intersection of two sorted arrays
Array *sorted_intersection(Array *array1, Array *array2)
{
    Array *array3 = new Array[array1->length];
    array3->length = 0, array3->size = 10;
    array3->A = new int[30];
    int i = 0, j = 0, k = 0;
    while ((i < array1->length) && (j < array2->length))
    {
        if (array1->A[i] < array2->A[j])
        {
            i++;
        }
        if (array1->A[i] > array2->A[j])
        {
            j++;
        }
        if (array1->A[i] == array2->A[j])
        {
            array3->A[k] = array2->A[j];
            j++;
            i++;
            k++;
            array3->length++;
        }
    }
    return array3;
}
// difference between unsorted two arrays
Array *unsorted_difference(Array *array1, Array *array2)
{
    Array *array3 = new Array[array1->length];
    array3->length = 0, array3->size = 10;
    array3->A = new int[30];
    int k = 0;
    for (int i = 0; i < array1->length; i++)
    {
        int v = L_search(array2, array1->A[i]);
        if (v != 1)
        {
            array3->A[k] = array1->A[i];
            k++;
            array3->length++;
        }
    }
    return array3;
}
// difference between two sorted arrays
Array *sorted_difference(Array *array1, Array *array2)
{
    Array *array3 = new Array[array1->length];
    array3->length = 0;
    array3->size = 10;
    array3->A = new int[30];
    int i, j, k;
    i = j = k = 0;
    while ((i < array1->length) && (j < array2->length))
    {
        if (array1->A[i] < array2->A[j])
        {
            array3->A[k] = array1->A[i];
            k++;
            i++;
            array3->length++;
        }
        if (array1->A[i] > array2->A[j])
        {
            j++;
        }
        if (array1->A[i] == array2->A[j])
        {
            j++;
            i++;
        }
    }
    for (; i < array1->length; i++)
    {
        array3->A[k] = array1->A[i];
        k++;
        array3->length++;
    }
    return array3;
}
int main()
{
    cout << "For array 1" << endl;
    Array arr;
    start(&arr);
    display(&arr);
    cout << endl;
    cout << "for array 2" << endl;
    Array arr1;
    start(&arr1);
    display(&arr1);
    cout << endl;
    Array *arr2 = sorted_union(&arr, &arr1);
    display(arr2);
    return 0;
}
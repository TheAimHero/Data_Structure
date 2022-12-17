/*
stack is a data structure that works on the discipline of last in first out.
Only the value entered last will be available for access,deletion and maniplation
*/
#include <iostream>
class Stack_Using_Array
{
private:
    int size, top, *array;

public:
    Stack_Using_Array(/* args */);
    void push(int value);
    void pop();
    int peek(int pos);
    int Top();
    int is_empty();
    int is_full();
    void display();
};

Stack_Using_Array::Stack_Using_Array(/* args */)
{
    std::cout << "Enter the size of the stack" << std::endl;
    std::cin >> size;
    array = new int[size];
    top = -1;
}

void Stack_Using_Array::push(int value)
{
    if (top == -1)
    {
        top++;
        array[top] = value;
        return;
    }

    if (size - top - 1)
    {
        top++;
        array[top] = value;
        return;
    }
    std::cout << "Stack Overflow." << std::endl;
}

void Stack_Using_Array::pop()
{
    if (top == -1)
    {
        std::cout << "Stack Empty." << std::endl;
        return;
    }
    top--;
}

int Stack_Using_Array::peek(int pos)
{
    if ((top == -1) || (top - pos - 1 < 0))
    {
        std::cout << "Invalid Position." << std::endl;
        return 0;
    }
    else
    {
        return (array[top - pos - 1]);
    }
}

int Stack_Using_Array::Top()
{
    if (top == -1)
    {
        std::cout << "Stack Empty." << std::endl;
        return -1;
    }
    return array[top];
}

int Stack_Using_Array::is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int Stack_Using_Array::is_full()
{
    if (!(size - top - 1))
    {
        return 1;
    }
    return 0;
}

void Stack_Using_Array::display()
{
    for (int i = 0; i < top; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Stack_Using_Array s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    std::cout << s.is_full();
    return 0;
}
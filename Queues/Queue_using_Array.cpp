#include <iostream>
class Queue_using_Array
{
private:
    int head, tail, n;
    int *array;

public:
    Queue_using_Array();
    void enqueue(int value);
    void dequeue();
    int front();
    int back();
    int empty();
    int size();
    int is_full();
};

Queue_using_Array::Queue_using_Array()
{
    std::cout << "Enter the size of the queue." << std::endl;
    std::cin >> n;
    head = tail = -1;
    array = new int[n];
}

void Queue_using_Array::enqueue(int value)
{
    if (tail == head)
    {
        head = tail = -1;
    }
    tail++;
    array[tail] = value;
}

void Queue_using_Array::dequeue()
{
    if (head == tail)
    {
        head = tail = -1;
        std::cout << "Queue Empty." << std::endl;
        return;
    }
    head++;
    if (head == tail)
    {
        head = tail = -1;
    }
}

int Queue_using_Array::front()
{
    if (tail == head)
    {
        head = tail = -1;
        std::cout << "Queue Empty." << std::endl;
        return -1;
    }
    return array[head + 1];
}

int Queue_using_Array::back()
{
    return array[tail];
}

int Queue_using_Array::empty()
{
    if (head == tail)
    {
        return 1;
    }
    return 0;
}

int Queue_using_Array::size()
{
    return tail - head;
}

int Queue_using_Array::is_full()
{
    if (tail == n - 1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    Queue_using_Array a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    std::cout << a.size() << std::endl;
    std::cout << a.empty() << std::endl;
    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    a.dequeue();
    return 0;
}
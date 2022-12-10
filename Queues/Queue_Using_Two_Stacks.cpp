#include <iostream>
#include <stack>
class Queue_Using_Two_Stacks
{
private:
    std::stack<int> s1, s2;

public:
    int enqueue(int value);
    void dequeue();
    int front();
    int back();
    int empty();
    int size();
};

int Queue_Using_Two_Stacks::enqueue(int value)
{
    s1.push(value);
}

void Queue_Using_Two_Stacks::dequeue()
{
    if (s1.empty() && s2.empty())
    {
        return;
    }
    if (s2.empty())
    {
        while (!(s1.empty()) && !(s1.empty()))
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}

int Queue_Using_Two_Stacks::front()
{
    if (s1.empty() && s2.empty())
    {
        std::cout << "Queue Empty.";
        return -1;
    }

    if (!(s2.empty()))
    {
        return s2.top();
    }

    if (s2.empty() && !(s1.empty()))
    {
        while (!(s1.empty()))
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

int Queue_Using_Two_Stacks::back()
{
    if (s1.empty())
    {
        std::stack<int> s3, s4;
        s4 = s2;
        while (!(s2.empty()))
        {
            s3.push(s2.top());
            s2.pop();
        }
        s2 = s4;
        return s3.top();
    }
    return s1.top();
}

int Queue_Using_Two_Stacks::empty()
{
    if (s1.empty() && s2.empty())
    {
        return 1;
    }
    return 0;
}

int Queue_Using_Two_Stacks::size()
{
    return s1.size() + s2.size();
}

int main()
{
    Queue_Using_Two_Stacks a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);

    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.back() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    return 0;
}
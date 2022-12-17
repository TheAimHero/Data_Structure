#include <iostream>
class node
{
public:
    int data;
    node *next;
};

class Queue_using_LL
{
private:
    node *head, *tail;

public:
    Queue_using_LL(/* args */);
    void enqueue(int value);
    void dequeue();
    int front();
    int back();
    int empty();
    int size();
};

Queue_using_LL::Queue_using_LL(/* args */)
{
    head = tail = NULL;
}

void Queue_using_LL::enqueue(int value)
{
    node *temp = new node;
    if (temp == NULL)
    {
        std::cout << "Queue Full." << std::endl;
        return;
    }
    if (head == NULL)
    {
        temp->data = value;
        temp->next = NULL;
        head = tail = temp;
    }
    else
    {
        temp->data = value;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void Queue_using_LL::dequeue()
{
    if (head == NULL)
    {
        std::cout << "Queue Empty." << std::endl;
        return;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

int Queue_using_LL::front()
{
    return head->data;
}

int Queue_using_LL::back()
{
    return tail->data;
}

int Queue_using_LL::empty()
{
    if (head == tail)
    {
        return 1;
    }
    return 0;
}

int Queue_using_LL::size()
{
    int count = 0;
    if (head == tail)
    {
        return count;
    }
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    Queue_using_LL a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    // std::cout << a.size() << std::endl;
    // std::cout << a.empty() << std::endl;
    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    a.dequeue();
    std::cout << a.front() << std::endl;
    a.dequeue();
}
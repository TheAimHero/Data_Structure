#include <iostream>
class node
{
public:
    int data;
    node *next;
};

class Stack_Using_LL
{
private:
    node *head;

public:
    Stack_Using_LL(/* args */);
    void display();
    void push(int value);
    void pop();
    int is_empty();
    int is_full();
    int top();
    int peek(int pos);
};

Stack_Using_LL::Stack_Using_LL(/* args */)
{
    head = new node;
    head = NULL;
}

void Stack_Using_LL::display()
{
    node *temp = head;
    if (head == NULL)
    {
        std::cout << "Linked list empty." << std::endl;
    }

    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void Stack_Using_LL::push(int value)
{
    node *n = new node;
    n->data = value;
    n->next = NULL;
    if (n == NULL)
    {
        std::cout << "Stack Overflow. " << std::endl;
        return;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

void Stack_Using_LL::pop()
{
    if (head == NULL)
    {
        std::cout << "Stack Empty." << std::endl;
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}

int Stack_Using_LL::is_empty()
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

int Stack_Using_LL::is_full()
{
    node *temp = new node;
    if (temp == NULL)
    {
        return 1;
    }
    return 0;
}

int Stack_Using_LL::top()
{
    if (head == NULL)
    {
        std::cout << "Stack Empty." << std::endl;
        return -1;
    }

    return head->data;
}

int Stack_Using_LL::peek(int pos)
{
    node *temp = head;
    for (int i = 0; temp != NULL && i < pos; i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return temp->data;
    }
    else
    {
        std::cout << "Position Invalid. ";
        return -1;
    }
}

int main()
{
    Stack_Using_LL a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.display();
    std::cout << a.peek(4);
    return 0;
}
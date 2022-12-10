#include <iostream>
class node
{
public:
    int data;
    node *previous, *next;
};
class Doubly_Linked_List
{
private:
    node *head, *tail;

public:
    Doubly_Linked_List(/* args */);
    void create_with_array(int a[], int num);
    void display();
    void delete_pos(int pos);
    int length(Doubly_Linked_List *a);
    void insert_pos(int pos, int value);
    void reverse();
};
Doubly_Linked_List::Doubly_Linked_List(/* args */)
{
    head = tail = new node;
    head = tail = NULL;
}
void Doubly_Linked_List::create_with_array(int a[], int num)
{
    node *temp, *ff;
    temp = ff = new node;
    temp->data = a[0];
    temp->previous = NULL;
    temp->next = NULL;
    head = tail = ff = temp;
    for (int i = 1; i < num; i++)
    {
        node *f = new node;
        f->data = a[i];
        f->next = NULL;
        f->previous = ff;
        tail->next = f;
        tail = f;
        ff = f;
    }
}
void Doubly_Linked_List::display()
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
void Doubly_Linked_List::delete_pos(int pos)
{
    node *temp;
    temp = head;
    if (pos == 0)
    {
        temp = head->next;
        head->next->previous = NULL;
        delete head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        delete temp;
    }
}
int Doubly_Linked_List::length(Doubly_Linked_List *a)
{
    if (a->head == NULL)
    {
        return 0;
    }
    int count = 0;
    node *temp = a->head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void Doubly_Linked_List::reverse()
{
    node *temp, *f;
    temp = f = head;
    while (temp != NULL)
    {
        f = temp;
        temp = temp->next;
        f->next = f->previous;
    }
    head = f;
}
void Doubly_Linked_List::Doubly_Linked_List::insert_pos(int pos, int value)
{
    node *temp = new node;
    temp = head;
    node *p = new node;
    p->data = value;
    p->next = p->previous = NULL;
    if ((pos > length(this) || pos < 0))
    {
        return;
    }
    if (pos == 0)
    {
        p->next = head;
        head = p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        p->next = temp->next;
        p->previous = temp;
        temp->next = p;
    }
}
int main()
{
    Doubly_Linked_List a;
    int arr1[10] = {1, 8, 15, 21, 58, 61, 45, 95, 88, 78};
    a.create_with_array(arr1, 10);
    a.display();
    a.delete_pos(0);
    a.display();
    return 0;
}

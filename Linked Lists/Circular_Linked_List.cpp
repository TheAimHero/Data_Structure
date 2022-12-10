#include <iostream>
class node
{
public:
    int data;
    node *next;
};
class Circular_Linked_List
{
private:
    node *head, *tail;

public:
    Circular_Linked_List(/* args */);
    void create_with_array(int a[], int num);
    void display();
    void insert(int value);
    void delete_value(int value);
};
Circular_Linked_List::Circular_Linked_List(/* args */)
{
    head = tail = new node;
    head = tail = NULL;
}
void Circular_Linked_List::create_with_array(int a[], int num)
{
    node *temp = new node;
    temp->data = a[0];
    head = temp;
    head->next = NULL;
    tail = head;
    for (int i = 1; i < num; i++)
    {
        node *p = new node;
        p->data = a[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    tail->next = head;
}
void Circular_Linked_List::display()
{
    node *temp;
    temp = head;
    do
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty;" << std::endl;
            return;
        }
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}
void Circular_Linked_List::insert(int value)
{
    node *temp = new node;
    temp->data = value;
    if (head == NULL)
    {

        temp->next = temp;
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
        tail->next = temp;
    }
}
void Circular_Linked_List::delete_value(int value)
{
    if (value == head->data)
    {
        tail->next = head->next;
        delete head;
        head = tail->next;
    }
    else
    {
        node *temp, *f;
        temp = f = head;
        do
        {
            if (temp->data == value)
            {
                f->next = temp->next;
                delete temp;
            }
            f = temp;
            temp = temp->next;
        } while (temp != head);
    }
}
int main()
{
    Circular_Linked_List a;
    // int arr1[9] = {1, 8, 15};
    // a.create_with_array(arr1, 3);
    // a.display();
    a.insert(1000);
    a.insert(101);
    a.display();
    // a.delete_value(1000);
    // a.display();
    return 0;
}
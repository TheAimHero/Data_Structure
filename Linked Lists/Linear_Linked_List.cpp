#include <iostream>
#include <cmath>
class node
{
public:
    int data;
    node *next;
};
class Linked_List
{
    node *head, *tail;

public:
    Linked_List(/* args */);
    void create_with_array(int a[], int num);
    void display();
    int length(Linked_List *p);
    int sum();
    int max();
    int L_search(int value);
    void pos_insert(int pos, int value);
    void last_insert(int value);
    void sorted_insert(int value);
    void pos_delete(int pos);
    int is_sorted();
    void remove_duplicate();
    void reverse();
    void append(Linked_List *q);
    void sort_LL();
    Linked_List sorted_merge(Linked_List *p, Linked_List *q);
    int is_loop();
    void make_loop(int pos);
    int middle();
};
Linked_List::Linked_List(/* args */)
{
    head = new node;
    tail = new node;
    tail = head;
    head = NULL;
}
void Linked_List::create_with_array(int a[], int num)
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
}
void Linked_List::display()
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
int Linked_List::length(Linked_List *p)
{
    int count = 0;
    node *temp = p->head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int Linked_List::sum()
{
    node *temp = this->head;
    int count = 0;
    while (temp != NULL)
    {
        count += temp->data;
        temp = temp->next;
    }
    return count;
}
int Linked_List::max()
{
    int max = 0;
    node *temp = this->head;
    while (temp != NULL)
    {
        if (max < temp->data)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}
int Linked_List::L_search(int value)
{
    node *temp = this->head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}
void Linked_List::pos_insert(int pos, int value)
{
    node *temp = this->head;
    node *n = new node;
    n->data = value;
    n->next = NULL;
    if (pos > length(this) || pos < 0)
    {
        return;
    }

    if (pos == 0)
    {
        n->next = head;
        head = n;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
    if (pos == length(this) - 1)
    {
        tail = n;
    }
}
void Linked_List::last_insert(int value)
{
    node *n = new node;
    n->data = value;
    if (length(this) == 0)
    {
        head = n;
        head->next = NULL;
        tail = head;
    }
    else
    {
        n->next = tail->next;
        tail->next = n;
        tail = n;
        tail->next = NULL;
    }
}
void Linked_List::sorted_insert(int value)
{
    node *temp = head;
    node *n = new node;
    n->data = value;
    if (head == NULL)
    {
        head = n;
        head->next = NULL;
    }
    else
    {
        if (temp->data > value)
        {

            n->next = head;
            head = n;
        }
        else
        {
            node *m = new node;
            m = temp;
            while (temp != NULL && temp->data < value)
            {
                m = temp;
                temp = temp->next;
            }
            n->next = m->next;
            m->next = n;
            if (n->next == NULL)
            {
                tail = n;
            }
        }
    }
}
void Linked_List::pos_delete(int pos)
{
    node *temp = head;
    if (pos < 0 || pos > length(this))
    {
        return;
    }
    else
    {
        if (pos == 0)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            node *f = head;
            for (int i = 0; i < pos; i++)
            {
                f = temp;
                temp = temp->next;
            }
            f->next = temp->next;
            delete temp;
        }
    }
}
int Linked_List::is_sorted()
{
    node *temp, *f;
    temp = head->next;
    f = head;
    if (head == NULL)
    {
        std::cout << "Linked list empty." << std::endl;
        return 0;
    }
    else
    {
        while (temp != NULL)
        {
            if (f->data > temp->data)
            {
                return 0;
            }
            f = temp;
            temp = temp->next;
        }
    }
    return 1;
}
void Linked_List::remove_duplicate()
{
    if (length(this) < 2)
    {
        return;
    }
    node *temp, *f;
    temp = head->next;
    f = head;
    while (temp != NULL)
    {
        if (f->data == temp->data)
        {
            f->next = temp->next;
            delete temp;
            temp = f->next;
        }
        else
        {
            f = temp;
            temp = temp->next;
        }
    }
}
void Linked_List::reverse()
{
    node *temp, *f, *ff;
    temp = head;
    f = ff = NULL;
    while (temp != NULL)
    {
        ff = f;
        f = temp;
        temp = temp->next;
        f->next = ff;
    }
    head = f;
}
void Linked_List::append(Linked_List *q)
{
    this->tail->next = q->head;
    this->tail = q->tail;
}
void Linked_List::sort_LL()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    node *temp1, *temp2;
    temp1 = temp2 = NULL;
    temp2 = head;
    temp1 = head->next;
    while (temp1 != NULL)
    {
        while (temp2 != NULL && temp1 != NULL)
        {
            if (temp2->data > temp1->data)
            {
                int temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }
}
Linked_List Linked_List::sorted_merge(Linked_List *p, Linked_List *q)
{
    node *temp1, *temp2;
    Linked_List r;
    temp1 = p->head;
    temp2 = q->head;
    if (!(p->is_sorted() && q->is_sorted()))
    {
        std::cout << "Invalid inputs.\nCheck if the arrays is sorted and none of them are empty.";
        return r;
    }
    else
    {
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                r.last_insert(temp2->data);
                temp2 = temp2->next;
            }
            else if (temp1->data < temp2->data)
            {
                r.last_insert(temp1->data);
                temp1 = temp1->next;
            }
            else
            {
                r.last_insert(temp2->data);
                temp2 = temp2->next;
                r.last_insert(temp1->data);
                temp1 = temp1->next;
            }
        }
        while (temp1 != NULL)
        {
            r.last_insert(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            r.last_insert(temp2->data);
            temp2 = temp2->next;
        }
        return r;
    }
}
int Linked_List::is_loop()
{
    node *temp1, *temp2;
    temp1 = temp2 = head;
    do
    {
        temp2 = temp2->next;
        temp1 = temp1->next;
        if (temp1 != NULL)
        {
            temp1 = temp1->next;
        }
        if (temp1 == temp2)
        {
            return 1;
        }
    } while (temp1 != NULL && temp2 != NULL);
    return 0;
}
void Linked_List::make_loop(int pos)
{
    node *temp1;
    temp1 = head;
    for (int i = 0; i < pos; i++)
    {
        temp1 = temp1->next;
    }
    tail->next = temp1;
}
int Linked_List::middle()
{
    node *temp, *f;
    temp = f = head;
    while (temp->next != NULL)
    {
        f = f->next;
        temp = temp->next->next;
    }
    std::cout << f->data;
}
int main()
{
    Linked_List a;
    int arr1[9] = {1, 8, 15, 21, 58, 61, 45, 95, 88};
    a.create_with_array(arr1, 9);
    a.display();
    a.middle();
    return 0;
}
#include <iostream>
#include <queue>
#include <stack>

class node
{
public:
    node *left_child, *right_child;
    int data;
};

class tree
{
private:
public:
    node *root;
    tree(/* args */);
    void create_by_lvl_order();
    void pre_order_display();
    void post_order_display();
    void in_order_display();
};

tree::tree()
{
    root = new node;
    root->left_child = root->right_child = NULL;
    std::cout << "Enter the data at root node : \n";
    std::cin >> root->data;
}

void tree::create_by_lvl_order()
{
    std::queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *p;
        p = q.front();
        q.pop();
        int x;
        std::cout << "Enter left child : \n";
        std::cin >> x;
        if (x != -1)
        {
            node *temp = new node;
            temp->data = x;
            temp->left_child = temp->right_child = NULL;
            p->left_child = temp;
            q.push(temp);
        }
        std::cout << "Enter right child : \n";
        std::cin >> x;
        if (x != -1)
        {
            node *temp = new node;
            temp->data = x;
            temp->left_child = temp->right_child = NULL;
            p->right_child = temp;
            q.push(temp);
        }
    }
}

void tree::pre_order_display()
{
    std::stack<node *> s;
    node *temp = root;
    while (!s.empty() || temp != NULL)
    {
        if (temp != NULL)
        {
            std::cout << temp->data << " ";
            s.push(temp);
            temp = temp->left_child;
        }
        else
        {
            temp = s.top();
            s.pop();
            temp = temp->right_child;
        }
    }
}

void tree::in_order_display()
{
    std::stack<node *> s;
    node *temp = root;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left_child;
        }
        else
        {
            temp = s.top();
            s.pop();
            std::cout << temp->data << " ";
            temp = temp->right_child;
        }
    }
}

void tree::post_order_display()
{
    std::stack<node *> s;
    node *temp = root;
    while (!s.empty() || temp != NULL)
    {
        if (temp != NULL)
        {
            s.push(temp);
            s.push(temp->right_child);
            temp = temp->left_child;
        }
        else
        {
            temp = s.top();
            s.pop();
            std::cout << temp->data << " ";
        }
    }
}

int main()
{
    tree a;
    a.create_by_lvl_order();
    a.post_order_display();
    return 0;
    // 1 2 3 -1 -1 -1 -1
    // 8 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
}
#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data, height = 1;
    node *left_child, *right_child;
};

class AVL_Tree
{
public:
    int node_height(node *temp);
    node *give_new_node(int value);
    node *in_order_predecessor(node *temp);
    node *in_order_successor(node *temp);
    int balance_factor(node *temp);
    node *balance(node *temp);
    node *LL_Rotation(node *temp);
    node *LR_Rotation(node *temp);
    node *RR_Rotation(node *temp);
    node *RL_Rotation(node *temp);
    node *Del_balance(node *temp);

public:
    node *root = NULL;
    int height(node *temp);
    node *insert(int value, node *temp);
    node *Del(int value, node *temp);
    void lvl_order_display();
};

node *AVL_Tree::Del_balance(node *temp)
{
    if ((balance_factor(temp) == 2) && (balance_factor(temp->left_child) == 1))
    {
        return LL_Rotation(temp);
    }
    else if (balance_factor(temp) == 2 && balance_factor(temp->left_child) == -1)
    {
        return LR_Rotation(temp);
    }
    else if (balance_factor(temp) == 2 && balance_factor(temp->left_child) == 0)
    {
        return LL_Rotation(temp);
    }
    else if (balance_factor(temp) == -2 && balance_factor(temp->right_child) == 1)
    {
        return RL_Rotation(temp);
    }
    else if (balance_factor(temp) == -2 && balance_factor(temp->right_child) == -1)
    {
        return RR_Rotation(temp);
    }
    else if (balance_factor(temp) == -2 && balance_factor(temp->right_child) == 0)
    {
        return RR_Rotation(temp);
    }
    return temp;
}

node *AVL_Tree::Del(int value, node *temp)
{
    if (temp == NULL)
    {
        return NULL;
    }
    if (temp->right_child == NULL && temp->left_child == NULL)
    {
        if (temp == root)
        {
            root = NULL;
        }
        free(temp);
        return NULL;
    }
    if (temp->data == value)
    {
        if (height(temp->left_child) > height(temp->right_child))
        {
            node *predecessor = in_order_predecessor(temp);
            temp->data = predecessor->data;
            temp->left_child = Del(predecessor->data, temp->left_child);
        }
        else
        {
            node *successor = in_order_successor(temp);
            temp->data = successor->data;
            temp->right_child = Del(successor->data, temp->right_child);
        }
    }
    else if (temp->data > value)
    {
        temp->left_child = Del(value, temp->left_child);
    }
    else if (temp->data < value)
    {
        temp->right_child = Del(value, temp->right_child);
    }
    return Del_balance(temp);
}

node *AVL_Tree::in_order_predecessor(node *temp)
{
    if (temp->left_child)
    {
        temp = temp->left_child;
        if (temp->right_child)
        {
            while (temp->right_child)
            {
                temp = temp->right_child;
            }

            return temp;
        }
    }
    return temp;
}

node *AVL_Tree::in_order_successor(node *temp)
{
    if (temp->right_child)
    {
        temp = temp->right_child;
        if (temp->left_child)
        {
            while (temp->left_child)
            {
                temp = temp->left_child;
            }
            return temp;
        }
    }
    return temp;
}

node *AVL_Tree::insert(int value, node *temp)
{
    if (temp == NULL)
    {
        return give_new_node(value);
    }
    if (temp->data > value)
    {
        temp->left_child = insert(value, temp->left_child);
    }
    else if (temp->data < value)
    {
        temp->right_child = insert(value, temp->right_child);
    }
    temp->height = node_height(temp);
    return balance(temp);
}

int AVL_Tree::node_height(node *temp)
{
    int x = 0, y = 0;
    x = temp && temp->left_child ? temp->left_child->height : 0;
    y = temp && temp->right_child ? temp->right_child->height : 0;
    return x > y ? x + 1 : y + 1;
}

node *AVL_Tree::give_new_node(int value)
{
    node *new_node = new node;
    new_node->left_child = new_node->right_child = NULL;
    new_node->height = 1;
    new_node->data = value;
    return new_node;
}

void AVL_Tree::lvl_order_display()
{
    std::queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            std::cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            std::cout << temp->data << "  ";
            if (temp->left_child)
            {
                q.push(temp->left_child);
            }
            if (temp->right_child)
            {
                q.push(temp->right_child);
            }
        }
    }
}

int AVL_Tree::balance_factor(node *temp)
{
    int x = 0, y = 0;
    x = temp && temp->left_child ? temp->left_child->height : 0;
    y = temp && temp->right_child ? temp->right_child->height : 0;
    return (x - y);
}

int AVL_Tree::height(node *temp)
{
    int x, y;
    x = y = 0;
    if (temp == NULL)
    {
        return 0;
    }
    x = height(temp->right_child);
    y = height(temp->right_child);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

node *AVL_Tree::balance(node *temp)
{
    if (balance_factor(temp) == 2 && balance_factor(temp->left_child) == 1)
    {
        return LL_Rotation(temp);
    }
    else if (balance_factor(temp) == 2 && balance_factor(temp->left_child) == -1)
    {
        return LR_Rotation(temp);
    }
    else if (balance_factor(temp) == -2 && balance_factor(temp->right_child) == -1)
    {
        return RR_Rotation(temp);
    }
    else if (balance_factor(temp) == -2 && balance_factor(temp->right_child) == 1)
    {
        return RL_Rotation(temp);
    }
    return temp;
}

node *AVL_Tree::LL_Rotation(node *temp)
{
    node *temp_lc = temp->left_child;
    temp->left_child = temp_lc->right_child;
    temp_lc->right_child = temp;
    temp = temp_lc;
    temp->height = height(temp);
    temp->right_child->height = height(temp->right_child);
    if (temp->right_child == root)
    {
        root = temp;
    }
    return temp;
}

node *AVL_Tree::RR_Rotation(node *temp)
{
    node *temp_rc = temp->right_child;
    temp->right_child = temp_rc->left_child;
    temp_rc->left_child = temp;
    temp = temp_rc;
    temp->height = height(temp);
    temp->left_child->height = height(temp->left_child);
    if (temp->left_child == root)
    {
        root = temp;
    }
    return temp;
}

node *AVL_Tree::LR_Rotation(node *temp)
{
    node *temp_lc = temp->left_child;
    node *temp_lrc = temp_lc->right_child;
    temp_lc->right_child = temp_lrc->left_child;
    temp->left_child = temp_lrc->right_child;
    temp_lrc->left_child = temp_lc;
    temp_lrc->right_child = temp;
    temp = temp_lrc;
    if (temp->right_child == root)
    {
        root = temp;
    }
    temp->height = height(temp);
    temp->left_child->height = height(temp->left_child);
    temp->right_child->height = height(temp->right_child);
    return temp;
}

node *AVL_Tree::RL_Rotation(node *temp)
{
    node *temp_rc = temp->right_child;
    node *temp_rlc = temp_rc->left_child;
    temp_rc->left_child = temp_rlc->right_child;
    temp->right_child = temp_rlc->left_child;
    temp_rlc->right_child = temp_rc;
    temp_rlc->left_child = temp;
    temp = temp_rlc;
    if (temp->left_child == root)
    {
        root = temp;
    }
    temp->height = height(temp);
    temp->right_child->height = height(temp->right_child);
    temp->left_child->height = height(temp->left_child);
    return temp;
}

int main()
{
    AVL_Tree t;
    t.root = t.insert(8, t.root);
    t.insert(6, t.root);
    t.insert(3, t.root);
    t.insert(1, t.root);
    t.insert(4, t.root);
    t.lvl_order_display();
    t.Del(8, t.root);
    cout << "\n \n";
    t.lvl_order_display();
    cout << endl;
    return 0;
}
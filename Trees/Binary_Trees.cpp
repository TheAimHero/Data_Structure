#include <iostream>
#include <queue>

class node {
public:
  node *left_child, *right_child;
  int data;
};

class tree {
private:
public:
  node *root;
  tree(/* args */);
  void create_by_lvl_order();
  void insert_lvl_order(int data);
  void lvl_order_display();
  void pre_order_display(node *temp);
  void post_order_display(node *temp);
  void in_order_display(node *temp);
  int count(node *temp);
  int height(node *temp);
  int count_leaf(node *temp);
};

tree::tree() {
  root = new node;
  root->left_child = root->right_child = NULL;
  std::cout << "Enter the data at root node : \n";
  std::cin >> root->data;
}

void tree::insert_lvl_order(int data) {
  node *new_node = new node;
  new_node->data = data;
  new_node->left_child = new_node->right_child = NULL;
  if (root == NULL) {
    root = new_node;
  }
  std::queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *temp = q.front();
    q.pop();
    if (temp->left_child) {
      q.push(temp->left_child);
    } else {
      temp->left_child = new_node;
      return;
    }
    if (temp->right_child) {
      q.push(temp->right_child);
    } else {
      temp->right_child = new_node;
      return;
    }
  }
}

void tree::create_by_lvl_order() {
  std::queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *p;
    p = q.front();
    q.pop();
    int x;
    std::cout << "Enter left child of " << p->data << " : \n";
    std::cin >> x;
    if (x != -1) {
      node *temp = new node;
      temp->data = x;
      temp->left_child = temp->right_child = NULL;
      p->left_child = temp;
      q.push(temp);
    }
    std::cout << "Enter right child of " << p->data << " : \n";
    std::cin >> x;
    if (x != -1) {
      node *temp = new node;
      temp->data = x;
      temp->left_child = temp->right_child = NULL;
      p->right_child = temp;
      q.push(temp);
    }
  }
}

void tree::lvl_order_display() {
  std::queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    node *temp = q.front();
    q.pop();
    if (temp == NULL) {
      std::cout << "\n";
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {

      std::cout << temp->data << "  ";
      if (temp->left_child) {
        q.push(temp->left_child);
      }
      if (temp->right_child) {
        q.push(temp->right_child);
      }
    }
  }
}

void tree::pre_order_display(node *temp) {

  if (temp == NULL) {
    return;
  }
  std::cout << temp->data << " ";
  pre_order_display(temp->left_child);
  pre_order_display(temp->right_child);
}

void tree::post_order_display(node *temp) {
  if (temp == NULL) {
    return;
  }
  post_order_display(temp->left_child);
  post_order_display(temp->right_child);
  std::cout << temp->data << " ";
}

void tree::in_order_display(node *temp) {
  if (temp == NULL) {
    return;
  }
  in_order_display(temp->left_child);
  std::cout << temp->data << " ";
  in_order_display(temp->right_child);
}

int tree::count(node *temp) {
  int x, y;
  x = y = 0;
  if (temp != NULL) {
    x = count(temp->left_child);
    y = count(temp->right_child);
    return x + y + 1;
  }
  return 0;
}

int tree::height(node *temp) {
  int x, y;
  x = y = 0;
  if (temp == NULL) {
    return 0;
  }
  x = height(temp->right_child);
  y = height(temp->right_child);
  if (x > y) {
    return x + 1;
  } else {
    return y + 1;
  }
}

int tree::count_leaf(node *temp) {
  int x = 0, y = 0;
  if (temp == NULL) {
    return 0;
  }
  x = count_leaf(temp->left_child);
  y = count_leaf(temp->right_child);
  if (temp->left_child == NULL && temp->right_child == NULL) {
    return x + y + 1;
  } else {
    return x + y;
  }
}

int main() {
  tree a;
  a.create_by_lvl_order();
  a.in_order_display(a.root);
  return 0;

  //  1 2 3 -1 -1 -1 -1
  //  1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
  //  30 20 40 10 25 35 50 -1 -1 -1 -1 -1 -1 -1 -1
}

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

Node *buildTree(string str) {
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = new Node(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size()) {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N") {

      // Create the left child for the current Node
      currNode->left = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N") {

      // Create the right child for the current node
      currNode->right = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

class Solution {
public:
  int res, k;
  void help(Node *root, unordered_set<int> &s) {
    if (!root) {
      return;
    }
    unordered_set<int> s1;
    help(root->left, s1);
    help(root->right, s1);
    s1.insert(root->data);

    for (auto i : s1) {
      s.insert(i);
    }
    if (s1.size() <= k)
      res++;
    return;
  }

  int goodSubtrees(Node *root, int k1) {
    res = 0;
    unordered_set<int> s;
    k = k1;
    help(root, s);
    return res;
  }
};

int main() {
  string str;
  getline(cin, str);
  int k;
  cin >> k;
  string newline;
  getline(cin, newline);
  Node *root = buildTree(str);
  Solution ob;
  cout << ob.goodSubtrees(root, k) << endl;
  return 0;
}

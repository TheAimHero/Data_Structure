#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *newNode(int val) {
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

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
  Node *root = newNode(stoi(ip[0]));

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

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

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
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution {

  void Dfs(unordered_map<int, vector<int>> &g, Node *root) {
    if (!root) {
      return;
    }
    if (root->right) {
      g[root->data].push_back(root->right->data);
      g[root->right->data].push_back(root->data);
      Dfs(g, root->right);
    }
    if (root->left) {
      g[root->data].push_back(root->left->data);
      g[root->left->data].push_back(root->data);
      Dfs(g, root->left);
    }
  }

  /*
  1 2 9 4 N 5 7 8 19 N N 20 11 30 N 40 50
  9 1

  5 3 6 1 4 N 10
  4 2
  */

public:
  int ladoos(Node *root, int home, int k) {
    unordered_map<int, vector<int>> g;
    Dfs(g, root);
    queue<vector<int>> q;
    int cnt = 0;
    q.push({home, k, -1});
    while (!q.empty()) {
      int cur = q.front()[0], step = q.front()[1], parent = q.front()[2];
      q.pop();
      cnt += cur;
      for (auto j : g[cur]) {
        if (step > 0 && j != parent) {
          q.push({j, step - 1, cur});
        }
      }
    }
    return cnt;
  }
};

//{ Driver Code Starts.
int main() {
  string s;
  getline(cin, s);
  Node *root = buildTree(s);
  int home, k;
  cin >> home >> k;
  getchar();
  Solution obj;
  cout << obj.ladoos(root, home, k) << endl;
  return 0;
}

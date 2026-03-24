#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// ─── Node ───────────────────────────────────────────────
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ─── BuildTree ──────────────────────────────────────────────
// Level order input: -1 means null
Node* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        Node* cur = q.front(); q.pop();
        if (vals[i] != -1) { cur->left  = new Node(vals[i]); q.push(cur->left);  } i++;
        if (i < vals.size() && vals[i] != -1) { cur->right = new Node(vals[i]); q.push(cur->right); } i++;
    }
    return root;
}

bool sumProperty(Node *root){
    if(!root || (!root->left && !root->right)) return true;
    int sum=0;
    
    if(root->left!=nullptr){
        sum += root->left->data;
    }
    if(root->right!=nullptr){
        sum += root->right->data;
    }
    
    return (sum == root->data) && (sumProperty(root->left) && sumProperty(root->right));
    
}

int main() {
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    //      -1 means null

    vector<int> vals = {10, 2, 8, 2, -1, 5, 3};
    Node* root = buildTree(vals);
    
    bool sumProp = sumProperty(root);
    
    cout<<sumProp<<endl;
    
    return 0;
}
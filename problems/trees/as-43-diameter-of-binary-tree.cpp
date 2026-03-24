// ─── Diameter of Binary Tree ──────────────────────────────────────────────

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

// ─── Build ──────────────────────────────────────────────
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



int diameter(Node *root,int &maxD){
    if(root==nullptr){
        return 0;
    }
    int lh=diameter(root->left,maxD);
    int rh=diameter(root->right,maxD);
    maxD=max(maxD,lh+rh);
    return 1+max(lh,rh);
}

int main() {
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7};
    Node* root = buildTree(vals);
    
    int maxD=0;
    int MaxDiameter = diameter(root,maxD);
    cout<<maxD;

    return 0;
}

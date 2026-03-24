// ─── Check if Binary Tree is Balanced ──────────────────────────────────────────────

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

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// ─── Function to check height & balance ─────────────────
int checkHeight(Node* root) {
    if (!root) return 0;

    int left = checkHeight(root->left);
    if (left == -1) return -1;  // left subtree not balanced

    int right = checkHeight(root->right);
    if (right == -1) return -1; // right subtree not balanced

    if (abs(left - right) > 1) return -1; // current node not balanced

    return max(left, right) + 1; // return height
}

// ─── Main balance checking function ─────────────────────
bool BalancedTree(Node* root) {
    return checkHeight(root) != -1;
}

// ─── Main Function ──────────────────────────────────────
int main() {
    //        10
    //      /   \
    //     20     30
    //    /  \   
    //   40   50 
    //  /
    // 60

    Node* r1 = new Node(10);
    r1->left = new Node(20);
    r1->right = new Node(30);
    r1->left->left = new Node(40);
    r1->left->right = new Node(50);
    r1->left->left->left = new Node(60);

    bool Balanced = BalancedTree(r1);

    if (Balanced)
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is NOT Balanced" << endl;

    return 0;
}

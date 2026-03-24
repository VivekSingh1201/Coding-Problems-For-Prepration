// This code defines a binary tree and calculates its height. The height of a binary tree is the number of edges on the longest path from the root to a leaf node. The code uses a recursive function to compute the height of the tree.


#include <iostream>
#include<algorithm>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node * root){
    if(root==nullptr){
        return -1;
    }
    
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    
    return max(lHeight,rHeight) + 1;
}

int main() {
    // 1. Create the Root
    Node* root = new Node(10);

    // 2. Add Level 1 children
    root->left = new Node(5);
    root->right = new Node(15);

    // 3. Add Level 2 children (Leaves)
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);
    
    //4
    root->left->right->left = new Node(7);
    
    //5
    root->left->right->left->right = new Node(7);
    

    int n = height(root);
    
    cout<<n<<endl;
    

    return 0;
}


// Time complexity: O(n) where n is the number of nodes in the tree, because we visit each node once to calculate the height.
// Space complexity: O(h) where h is the height of the tree, because of the recursive call stack. In the worst case (skewed tree), the space complexity can be O(n).
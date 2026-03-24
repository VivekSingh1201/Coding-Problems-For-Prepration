// Check if two binary trees are identical
// Two binary trees are identical if they have the same structure and the same node values. We can use a recursive approach to check if the two trees are identical. We can compare the data of the current nodes of both trees and then recursively check the left and right subtrees. If all the comparisons return true, then the trees are identical; otherwise, they are not.

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

// Function to check if two trees are identical

bool Identical(Node *r1,Node *r2){
    if(r1==nullptr && r2==nullptr){
        return true;
    }
    
    if(r1==nullptr || r2==nullptr){
        return false;
    }
    
    return (r1->data == r2-> data) && Identical(r1->left,r2->left) && Identical(r1->right,r2->right);
    
}

int main() {
    // 1. Create the Root
    Node* r1 = new Node(10);

    // 2. Add Level 1 children
    r1->left = new Node(5);
    r1->right = new Node(15);

    // 3. Add Level 2 children (Leaves)
    r1->left->left = new Node(2);
    r1->left->right = new Node(7);
    r1->right->left = new Node(12);
    r1->right->right = new Node(20);
    
    //4
    r1->left->right->left = new Node(7);
    
    //5
    r1->left->right->left->right = new Node(7);
    
    
     // 1. Create the Root
    Node* r2 = new Node(10);

    // 2. Add Level 1 children
    r2->left = new Node(5);
    r2->right = new Node(15);

    // 3. Add Level 2 children (Leaves)
    r2->left->left = new Node(2);
    r2->left->right = new Node(7);
    r2->right->left = new Node(12);
    r2->right->right = new Node(20);
    
    //4
    r2->left->right->left = new Node(7);
    
    //5
    r2->left->right->left->right = new Node(7);

    bool n = Identical(r1,r2);
    
    cout<<n<<endl;
    

    return 0;
}


// Time complexity: O(n) where n is the number of nodes in the trees (assuming both trees have the same number of nodes).
// Space complexity: O(h) where h is the height of the trees, due to the recursive call stack. In the worst case (skewed tree), this can be O(n).
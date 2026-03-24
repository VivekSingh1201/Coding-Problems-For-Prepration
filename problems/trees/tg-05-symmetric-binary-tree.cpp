// Check if a binary tree is a mirror of itself (symmetric around its center)
// A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree. We can use a queue to perform a level order traversal of the tree and compare the nodes at each level. We can enqueue the left and right children of the nodes in pairs and compare them. If any pair of nodes is not equal, then the tree is not symmetric; otherwise, it is symmetric.


#include <iostream>
#include<algorithm>
#include <queue>
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

bool Mirror(Node *root){
    if(root==nullptr){
        return true;
    }
    
    queue<Node *> q;
    
    q.push(root->left);
    q.push(root->right);
    
    while(!q.empty()){
        Node * node1 = q.front();
        q.pop();
        Node *node2 = q.front();
        q.pop();
        
        if(node1==nullptr && node2==nullptr){
            continue;
        }
        if(node1==nullptr || node2==nullptr || node1-> data != node2->data){
            return false;
        }
        
        q.push(node1->left);
        q.push(node1->right);
        q.push(node2->left);
        q.push(node2->right);
    }
    return true;
}
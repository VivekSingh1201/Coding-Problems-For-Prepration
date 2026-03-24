// ─── Binary Tree Traversals and Properties ──────────────────────────────────────────────

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

// ─── Traversals ─────────────────────────────────────────
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node* cur = q.front(); q.pop();
            cout << cur->data << ' ';
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << '\n';
    }
}

// ─── Height ─────────────────────────────────────────────
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// ─── Diameter ───────────────────────────────────────────
int diameter(Node* root, int& maxD) {
    if (!root) return 0;
    int lh = diameter(root->left,  maxD);
    int rh = diameter(root->right, maxD);
    maxD = max(maxD, lh + rh);
    return 1 + max(lh, rh);
}

// ─── LCA ──────────────────────────────────────────────── 
Node* lca(Node* root, int a, int b) {
    if (!root || root->data == a || root->data == b) return root;
    Node* left  = lca(root->left,  a, b);
    Node* right = lca(root->right, a, b);
    if (left && right) return root;
    return left ? left : right;
}

// ─── Path from root to node ─────────────────────────────
bool getPath(Node* root, int target, vector<int>& path) {
    if (!root) return false;
    path.push_back(root->data);
    if (root->data == target) return true;
    if (getPath(root->left, target, path) || getPath(root->right, target, path)) return true;
    path.pop_back();
    return false;
}

// ─── Check Balanced ─────────────────────────────────────
int isBalanced(Node* root) {
    if (!root) return 0;
    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);
    if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

// ─── Max Path Sum ───────────────────────────────────────
int maxPathSum(Node* root, int& maxSum) {
    if (!root) return 0;
    int lsum = max(0, maxPathSum(root->left,  maxSum));
    int rsum = max(0, maxPathSum(root->right, maxSum));
    maxSum = max(maxSum, lsum + rsum + root->data);
    return root->data + max(lsum, rsum);
}

// ─── Zigzag Level Order ─────────────────────────────────
vector<vector<int>> zigzag(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front(); q.pop();
            int idx = leftToRight ? i : sz - i - 1;
            level[idx] = cur->data;
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        leftToRight = !leftToRight;
        res.push_back(level);
    }
    return res;
}

// ─── Right / Left View ──────────────────────────────────
void rightView(Node* root, int level, vector<int>& res) {
    if (!root) return;
    if (level == res.size()) res.push_back(root->data);
    rightView(root->right, level + 1, res);
    rightView(root->left,  level + 1, res);
}

// ─── Main ───────────────────────────────────────────────
int main() {
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7};
    Node* root = buildTree(vals);

    cout << "Inorder:    "; inorder(root);   cout << '\n';
    cout << "Preorder:   "; preorder(root);  cout << '\n';
    cout << "Postorder:  "; postorder(root); cout << '\n';
    cout << "LevelOrder:\n"; levelOrder(root);

    cout << "Height:     " << height(root) << '\n';

    int maxD = 0;
    diameter(root, maxD);
    cout << "Diameter:   " << maxD << '\n';

    cout << "LCA(4,5):   " << lca(root, 4, 5)->data << '\n';

    vector<int> path;
    getPath(root, 6, path);
    cout << "Path to 6:  ";
    for (int x : path) cout << x << ' ';
    cout << '\n';

    cout << "Balanced:   " << (isBalanced(root) != -1 ? "Yes" : "No") << '\n';

    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);
    cout << "MaxPathSum: " << maxSum << '\n';

    cout << "Zigzag:\n";
    for (auto& row : zigzag(root)) {
        for (int x : row) cout << x << ' ';
        cout << '\n';
    }

    vector<int> rv;
    rightView(root, 0, rv);
    cout << "RightView:  ";
    for (int x : rv) cout << x << ' ';
    cout << '\n';

    return 0;
}


// ```

// ---

// ## Output
// ```
// Inorder:    4 2 5 1 6 3 7
// Preorder:   1 2 4 5 3 6 7
// Postorder:  4 5 2 6 7 3 1
// LevelOrder:
// 1
// 2 3
// 4 5 6 7
// Height:     3
// Diameter:   4
// LCA(4,5):   2
// Path to 6:  1 3 6
// Balanced:   Yes
// MaxPathSum: 18
// Zigzag:
// 1
// 3 2
// 4 5 6 7
// RightView:  1 3 7
#include <bits/stdc++.h>
using namespace std;

// AVL Tree Node
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode(int key) : data(key), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the Height of the tree
int Height(TreeNode *root) {
    return root ? root->height : 0;
}

// Function to get the Balance Factor of the tree
int getBalance(TreeNode *root) {
    return root ? Height(root->left) - Height(root->right) : 0;
}

// Function to rotate Left
TreeNode* LeftRotate(TreeNode *x) {
    TreeNode* y = x->right;
    x->right = y->left;
    y->left = x;
    
    x->height = 1 + max(Height(x->left), Height(x->right));
    y->height = 1 + max(Height(y->left), Height(y->right));

    return y;
}

// Function to rotate Right
TreeNode* RightRotate(TreeNode *x) {
    TreeNode* y = x->left;
    x->left = y->right;
    y->right = x;

    x->height = 1 + max(Height(x->left), Height(x->right));
    y->height = 1 + max(Height(y->left), Height(y->right));

    return y;
}

// Function to Insert a value in the tree
TreeNode* Insertion(TreeNode *root, int key) {
    if (!root) return new TreeNode(key);

    if (key < root->data) {
        root->left = Insertion(root->left, key);
    } else if (key > root->data) {
        root->right = Insertion(root->right, key);
    } else {
        return root; // Duplicate keys are not allowed
    }

    root->height = 1 + max(Height(root->left), Height(root->right));

    int balanceFactor = getBalance(root);

    if (balanceFactor > 1) {
        if (key < root->left->data) {
            return RightRotate(root); // Left Left Case
        } else {
            root->left = LeftRotate(root->left);
            return RightRotate(root); // Left Right Case
        }
    }
    
    if (balanceFactor < -1) {
        if (key > root->right->data) {
            return LeftRotate(root); // Right Right Case
        } else {
            root->right = RightRotate(root->right);
            return LeftRotate(root); // Right Left Case
        }
    }

    return root;
}

TreeNode* minValue(TreeNode *root) {
    TreeNode *temp = root;
    while (temp->left) {
        temp = temp->left;
    }
    return temp;
}

// Function to Delete a value in the AVL tree
TreeNode* Delete(TreeNode *root, int key) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = Delete(root->left, key);
    } else if (key > root->data) {
        root->right = Delete(root->right, key);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValue(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }

    if (!root) return nullptr;

    root->height = 1 + max(Height(root->left), Height(root->right));

    int balanceFactor = getBalance(root);

    if (balanceFactor > 1) {
        if (getBalance(root->left) >= 0) {
            return RightRotate(root); // Left Left Case
        } else {
            root->left = LeftRotate(root->left);
            return RightRotate(root); // Left Right Case
        }
    }
    
    if (balanceFactor < -1) {
        if (getBalance(root->right) <= 0) {
            return LeftRotate(root); // Right Right Case
        } else {
            root->right = RightRotate(root->right);
            return LeftRotate(root); // Right Left Case
        }
    }

    return root;
}

// Function to Print the tree values
void inorder(TreeNode *root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }
    
    TreeNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = Insertion(root, nodes[i]);
    }

    inorder(root);
    cout << endl;

    int dlt;
    cin >> dlt;

    root = Delete(root, dlt);
    cout << endl;

    inorder(root);
    cout << endl;
}
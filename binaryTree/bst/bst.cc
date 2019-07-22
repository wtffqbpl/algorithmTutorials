#include <iostream>
#include <vector>


using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* p;  // pointer to parent.

    TreeNode()
        : key(0)
        , left(nullptr)
        , right(nullptr)
        , p(nullptr) {}

    TreeNode(int val)
        : key(key)
        , left(nullptr)
        , right(nullptr)
        , p(nullptr) {}
};

void inorder_tree_walk(TreeNode* root)
{
    if (nullptr != root) {
        inorder_tree_walk(root->left);
        cout << root->key << " ";
        inorder_tree_walk(root->right);
    }
}

void preorder_tree_walk(TreeNode* root)
{
    if (nullptr != root) {
        cout << root->key << " ";
        preorder_tree_walk(root->left);
        preorder_tree_walk(root->right);
    }
}

TreeNode* tree_search(TreeNode* root, int val)
{
    if ((nullptr == root) || (val == root->key)) return root;

    if (val < root->key) {
        return tree_search(root->left, val);
    } else {
        return tree_search(root->right, val);
    }
}

TreeNode* tree_minmum(TreeNode* root)
{
    while (nullptr != root->left) {
        root = root->left;
    }
        return root;
}

TreeNode* tree_maxmum(TreeNode* root)
{
    while (nullptr != root->right) {
        root = root->right;
    }
    return root;
}

TreeNode* tree_successor(TreeNode* root)
{
    if (nullptr != root->right) {
        return tree_minmum(root->right);
    }
    TreeNode* y = root->p;

    while (y && (root == y->right)) {
        root = y;
        y = y->p;
    }

    return y;
}

TreeNode* tree_predecessor(TreeNode* root)
{
    if (root->left) {
        return tree_maxmum(root->left);
    }

    TreeNode* y  = root->p;
    while (y && (root == y->left)) {
        root = y;
        y = y->p;
    }

    return y;
}

void tree_insert(TreeNode* T, TreeNode* z)
{
    TreeNode* x = T;
    TreeNode* y;

    while (x) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->p = y;
    if (nullptr == y) {
        T = z;
    } else if(z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void transplant(TreeNode* T, TreeNode* u, TreeNode* v)
{
    if (nullptr == u->p) {
        T = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }

    if (v) {
        v->p = u->p;
    }
}

void tree_delete(TreeNode* T, TreeNode* z)
{
    if (nullptr == z->left) {
        transplant(T, z, z->right);
    } else if(nullptr == z->right) {
        transplant(T, z, z->left);
    } else {
        TreeNode* y = tree_minmum(z->right);
        if (y->p != z) {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }

        transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}

int main()
{
    TreeNode* t = new TreeNode(15);

    int a[10] = {6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    for (int i = 0; i < 10; ++i) {
        TreeNode* z = new TreeNode(a[i]);
        tree_insert(t, z);
    }

    inorder_tree_walk(t); 
    cout << endl;

    preorder_tree_walk(t);

    TreeNode* min = tree_minmum(t);
    TreeNode* max = tree_maxmum(t);
    cout << endl;

    cout << "Maximum: " << max->key << ", Minimum: " << min->key << endl;
    cout << "Find Node where z = 13:  ";
    TreeNode* z = tree_search(t, 13);
    cout << z->key << endl;

    TreeNode* prez = tree_predecessor(z);
    TreeNode* sucz = tree_successor(z);

    cout << "The predecessor of Z is : " << prez->key << " " << "The successor of Z is : " << sucz->key << endl;

    tree_delete(t, z);

    cout << "After deletion of z: ";
    inorder_tree_walk(t);
    cout << endl;
}

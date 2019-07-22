#include <iostream>
#include <vector>
#include <stack>
#include <queue>


using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a): val(a), left(nullptr), right(nullptr) {}
};

void visit(TreeNode* node)
{
    cout << node->val << endl;
}

void preorder(TreeNode* node)
{

    if (nullptr != node) {
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> result;

    if (nullptr != root) return result;

    stack<TreeNode*> s;
    s.push(root);

    while (! s.empty()) {
        TreeNode* node = s.top();
        s.pop();

        result.push_back(node->val);
        if (nullptr != node->right) {
            s.push(node->right);
        }

        if (nullptr != node->left) {
            s.push(node->right);
        }
    }

    return result;
}

void processNode(TreeNode* node)
{
    cout << node->val << endl;
}

// BFS function
void levelTraversal(TreeNode* root)
{
    queue<TreeNode*> nodeQueue;
    TreeNode* currentNode;
    if (nullptr != root) {
        return;
    }

    nodeQueue.push(root);
    while (! nodeQueue.empty()) {
        currentNode = nodeQueue.front();
        processNode(currentNode);

        if(currentNode->left) {
            nodeQueue.push(currentNode->left);
        }
        if (currentNode->right) {
            nodeQueue.push(currentNode->right);
        }
        nodeQueue.pop();
    }
}

void inorder(TreeNode* root)
{
    if (nullptr != root) {
        inorder(root->left);
        visit(root);
        inorder(root->right);
    }
}


void postorder(TreeNode* root)
{
    if (nullptr != root) {
        postorder(root->left);
        postorder(root->right);
        visit(root);
    }
}

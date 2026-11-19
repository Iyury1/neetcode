
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* findMinNode(TreeNode* root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root)
        {
            return nullptr;
        }

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (!root->left)
            {
                TreeNode* desc = root->right;
                delete root;
                return desc;
            }
            if (!root->right)
            {
                TreeNode* desc = root->left;
                delete root;
                return desc;
            }
            // Delete node while maintaining BST ordering:
            // The min node from the right side will be smaller
            // than the right node, but greater than the left
            TreeNode* minNode = findMinNode(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
};
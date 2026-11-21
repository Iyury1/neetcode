#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_Recursive {
public:

    void dfs(TreeNode* root, vector<int>& ret)
    {
        if (!root) return;
        dfs(root->left, ret);
        ret.push_back(root->val);
        dfs(root->right, ret);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
};


class Solution_Iterative1 {
public:


    vector<int> inorderTraversal(TreeNode* root) {
        // This version could support post order
        // by adding a third state.
        vector<int> ret;

        stack<TreeNode*> s;
        // state:
        // 0 - unvisited
        // 1 - left traversed
        unordered_map<TreeNode*, int> state;

        if (root)
        {
            s.push(root);
        }
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            int curr_state = state[curr];
            if (curr_state == 0)
            {
                if (curr->left)
                {
                    s.push(curr->left);
                }
                state[curr] = 1;
            }
            else
            {
                ret.push_back(curr->val);
                s.pop();
                if (curr->right)
                {
                    s.push(curr->right);
                }
            }
        }
        return ret;
    }
};

class Solution_Iterative2 {
public:


    vector<int> inorderTraversal(TreeNode* root) {
        // Removes memory cost of map
        vector<int> ret;
        stack<pair<TreeNode*, bool>> s;

        if (root)
        {
            s.push({root, false});
        }
        while(!s.empty())
        {
            auto& [curr, visited] = s.top();
            if (!visited)
            {
                if (curr->left)
                {
                    s.push({curr->left, false});
                }
                visited = true;
            }
            else
            {
                ret.push_back(curr->val);
                s.pop();
                if (curr->right)
                {
                    s.push({curr->right, false});
                }
            }
        }
        return ret;
    }
};


class Solution_Iterative3 {
public:


    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ret;
        stack<TreeNode*> s;

        TreeNode* curr = root;

        while (curr || !s.empty())
        {
            while (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top(); s.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }

        return ret;
    }
};


/*
Non-recusive in-order traveral without a stack and leaves the tree unmodified.


https://www.geeksforgeeks.org/?p=6358
https://liacs.leidenuniv.nl/~hoogeboomhj/dat/ohp/dat-present-24-2.pdf

J. M. Morris, Traversing binary trees simply and cheaply, Information Processing Lett. 9 (1979), 197–200

Fenner, T. I., & Loizou, G. (1986). A study of binary tree traversal algorithms and a tag-free threaded representation. International Journal of Computer Mathematics, 20(3–4), 171–185. https://doi.org/10.1080/00207168608803542

class Solution_MorrisTraversal {
public:


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* curr = root;

        while (curr)
        {
            if (!curr->left)
            {
                ret.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }
                if (!pred->right)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = nullptr;
                    ret.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ret;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//if only 1 node? - true
//if equal ?  - false
// state: at every stage -> l, r nodes should be less and high from root and also 
// 10 2 12 1
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        int r = INT_MAX;
        int l = INT_MIN;
        return dfs(root, l, r);
    }

    bool dfs(TreeNode *root, int l, int r)
    {
        if(root == nullptr)
            return true;

        if(!((root->val < r) && (root->val > l)) )
              return false;

        return (dfs(root->left, l, root->val) && 
                dfs(root->right, root->val, r));
    }
};

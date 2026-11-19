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

// if( abs(lh-rh) > 1 ) return false 
// else true 

class Solution {
public:
    bool ret = true;

    int treeHeight(TreeNode* root )
    {
        if(root == nullptr)
            return 0;
        int lh = treeHeight(root->left);
        int rh = treeHeight(root->right);
        if(abs(lh - rh) > 1)
            ret = false;
        return 1+ max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        treeHeight(root);
        return ret;
    }
};

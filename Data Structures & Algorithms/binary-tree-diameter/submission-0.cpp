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

//diamater =  depth(root->left) + depth(root->right)

class Solution {
public:
    int diameter = INT_MIN;
    int maxDepth(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
// Update the max diameter found so far at THIS specific node
        diameter = max (diameter, ld+rd);
// Return the height of this node to its parent
        return 1+ max(ld,rd);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
};

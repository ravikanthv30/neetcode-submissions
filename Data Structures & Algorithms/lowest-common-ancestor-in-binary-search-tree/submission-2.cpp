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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * curr = root;

        while(curr != nullptr)
        {
            //if both are less than curr -> go left tree 
            if(p->val < curr->val && q->val < curr->val)
            {
                curr = curr->left;
            }
            //if both are more than curr  -> go right  tree 
            else if(p->val > curr->val && q->val > curr->val)
            {
                curr = curr->right;
            }
            else
            {
                return curr;
            }
        }
        return nullptr;
    }
};

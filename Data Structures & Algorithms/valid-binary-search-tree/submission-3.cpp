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
    bool isValidBST(TreeNode* root) {
        //output is bool -> so if false return
        //if (root->val < root->left->val ||  root->val > root->right->val ) - return false
        // DFS and BFS ->BFS as we can return there itself

        queue <tuple<TreeNode*, int, int>> q;
        q.push({root, INT_MIN, INT_MAX});
        while(! q.empty())
        {
            int lsize = q.size();
            for(int i=0; i<lsize; i++)
            {
                auto [curr, l , r] = q.front();
                q.pop();
                //do not do operaiton on next values, always try on current value
                if( !((curr->val > l ) && (curr->val <r)) )
                    return false;
                if(curr->left)
                {
                    q.push({curr->left,l,curr->val});
                }
                if(curr->right)
                {
                    q.push({curr->right,curr->val, r});
                }
            }
        }
        return true;
    }
};

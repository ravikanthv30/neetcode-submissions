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

// right view -> input root and out -> vector list of number 
// same level what is the right most element 
// 1 , 2 3 ,  4,  5 
// 1 23 45 

class Solution {
public:


    vector<int> rightSideView(TreeNode* root) {
        //create a level order  o(n)
        //while ()
        //pick right most elements o(h) // o(n) ; o(n)
        //for 

        vector<int> res;
        if(root == nullptr)
            return res;
        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> curr_level;
            for(int i = 0; i< levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                curr_level.push_back(curr->val);
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
            }
            res.push_back(curr_level.front());
        }

        return res;
    }
};

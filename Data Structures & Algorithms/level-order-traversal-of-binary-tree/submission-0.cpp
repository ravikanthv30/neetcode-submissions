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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }
        vector<vector<int>> res;
        queue <TreeNode*> q;
        q.push(root);
        int level=0;

        while(!q.empty())
        {
            int size= q.size();
            vector<int> lt;
            for(int i=0;i<size;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                lt.push_back(n->val);
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            if(lt.size())
                res.push_back(lt);
            level++;     
        }
        return res;
    }
};

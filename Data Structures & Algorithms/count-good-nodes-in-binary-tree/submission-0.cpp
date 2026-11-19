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
//input is only tree root;  
// output - number of good nodes 
// Good nodes -> path to root to X --> max == x
//for list of all paths from root each path max <=x -> count 
// state: if( curr_max > curr->val)
    //ret++;
//curr_max = max (curr_max, curr->val)

class Solution {
    
    int ret{0};
public:

    void dfs(TreeNode* root, int curr_max)
    {
        if(root == nullptr)
            return;
        //cout<<curr_max<<" " << root->val<<endl;
        curr_max = max (curr_max, root->val);
        if(curr_max == root->val)
            ret++;
        dfs(root->left,curr_max);
        dfs(root->right, curr_max);
    }
    int goodNodes(TreeNode* root) {
        int curr_max{INT_MIN};
        dfs(root, curr_max);
        return ret;
    }
};

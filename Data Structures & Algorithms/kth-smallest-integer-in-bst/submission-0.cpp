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
//do in order traversal DFS and we should be able to get a vector and return kth elemeent from there -> o(n) and O(n)
//null-> return -1? // 1 node ; // negative values ?
class Solution {
public:
    void dfs(TreeNode* root,  vector <int> &list)
    {
        if(root == nullptr)
            return;
        dfs(root->left, list);
        list.push_back(root->val);
        dfs(root->right, list);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector <int> list;

        if((root == nullptr) || k <=0)
            return 0;
        //dfs 
        dfs(root,list);
        //get the vector 
        if(k > list.size())
            return 0;
        //return kth element
        return list[k-1];
    }
};

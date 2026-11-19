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
// 2 problems - O(n) space should be O(1) and O(n) should be O(k)
// iterative is better, but queue does per level and takes out first ;
// need to go left first  
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {

        int n =0 ;
        if((root == nullptr) || k <=0)
            return 0;
        stack <TreeNode*> s;
        //s.push(root);
        TreeNode* curr = root;
        while(!s.empty()  || curr !=nullptr)
        {
            while(curr != NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            n++;
            curr = s.top();
            s.pop();
            if(n==k)
                return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};

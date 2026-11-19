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

 // LCA -> if there is a path to p to q and level lowest level ?
 // can I do level order traversal -> 5, 3  , 1 4 , 2 
//                                       8  , 7 9 , 
// Trace path from root to bode [5 -> 3 -> 1 -> 2] [5 -> 8 -> 9]
// its a BST -> so I can travese according to the value 
//2 vectors path to root 
// 5->3 ; 5->3->4
//
class Solution {
public:

    void getRootPath(TreeNode* root, TreeNode* v, vector<TreeNode*> &p)
    {
        if(root == nullptr   || v == nullptr )
            return;
        TreeNode* ptr = root;

        while(ptr)
        {
            p.push_back(ptr);
            if(ptr->val == v->val)
                break;
            else if(v->val < ptr->val)
                ptr = ptr->left;
            else if(v->val > ptr->val)
                ptr = ptr->right;
        }
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr   || p == nullptr  || q == nullptr)
            return nullptr;        
        vector<TreeNode*> pp;
        vector<TreeNode*> qp;
        //get path for both
        getRootPath(root, p, pp);
        getRootPath(root, q, qp);

        //find the lowest same one
        TreeNode* ret = root;
        int i = 0; 
        int j = 0; 
        int m = min(pp.size(), qp.size());
        while( i<pp.size() || j<qp.size() )
        {
            if((min(i,j) < m) && pp[i]->val == qp[j]->val)
                ret = pp[i];
            if(i<pp.size())
            {
                i++;
            }
            if(j<qp.size())
            {
                j++;
            }
        }
        return ret;

    }
};

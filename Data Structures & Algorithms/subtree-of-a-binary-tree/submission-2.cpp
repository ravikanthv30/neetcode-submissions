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

//Regression would be good choice here .. 
//pass the root node of tree and subroot --> compare if same tree or not ?
//if yes -> return true 
//if no --> move to the next left, subroot or right, subroot 
//breaking condition is to return if current nodes are NOT same 

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL && subRoot == NULL)
            return true;
        else if(! (root && subRoot))
            return false;

         if ((root->val == subRoot->val) && isSameTree(root, subRoot))
            return true;
            
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL && subRoot == NULL)
            return true;
        else if(! (root && subRoot))
            return false;
        else if (root->val != subRoot->val)
            return false;
        
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right) ;
    }
};

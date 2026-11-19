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

//input- 2 order traversal --> why ? to create inorder do we need both ?
// pre=rolr ; in= lror
// 1 2 3 4  ;  2 1 3 4
//
//start --> l, r 
    // pre[0] == root - so find that inorder at i
    // lefttree in[l-i]  root = in[1];  righttree in[i+1, r]
    // if(i-l == 1) - create a node and attach as left to curr node
    // if (r-i == 1) - create a node and attach as left to curr node
// tree(pre,in, l, r)
//  in subtree  pre[i] == root =>  if same as in[i] no left subtree only right 
// 
//
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = nullptr;
        if(preorder.size()==0 ||inorder.size()==0 )
            return res;
        int preindex=0;
        return doTree(preorder, inorder, preindex, 0, preorder.size()-1);
    }

    TreeNode* doTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int l, int r) {
        if (l > r) return nullptr;
        
        // 1. The current root is always at the current preIndex
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++; // Move to the next preorder element for subsequent calls
        
        // 2. Find this root's position in the inorder array
        auto it = find(inorder.begin() + l, inorder.begin() + r + 1, root->val);
        int mid = std::distance(inorder.begin(), it);
        
        // 3. Recursively build left and right subtrees
        root->left = doTree(preorder, inorder, preIndex, l, mid - 1);
        root->right = doTree(preorder, inorder, preIndex, mid + 1, r);
        
        return root;
    }
};
 
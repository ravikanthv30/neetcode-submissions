class Solution {
private:
    unordered_map<int, int> um;
    
    TreeNode* doTree(vector<int>& preorder, int l, int r, int& preIndex) {
        if (l > r) return nullptr;
        
        // 1. The current root is always at the current preIndex
        int rootVal = preorder[preIndex];
        preIndex++; // Advance automatically for the next recursive call
        
        TreeNode* root = new TreeNode(rootVal);
        int mid = um[rootVal];
        
        // 2. Recursively build left and right subtrees
        root->left = doTree(preorder, l, mid - 1, preIndex);
        root->right = doTree(preorder, mid + 1, r, preIndex);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            um[inorder[i]] = i;
        }
        int preIndex = 0;
        return doTree(preorder, 0, preorder.size() - 1, preIndex);
    }
};
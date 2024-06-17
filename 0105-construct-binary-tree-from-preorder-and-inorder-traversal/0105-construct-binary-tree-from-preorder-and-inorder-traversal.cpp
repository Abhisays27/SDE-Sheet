class Solution {
private:
    TreeNode* solve(const vector<int>& preorder, int sP, int eP, const vector<int>& inorder, int sI, int eI, unordered_map<int, int>& mpp) {
        // Base condition
        if (sI > eI || sP > eP) return NULL;

        // Create the root node
        TreeNode* root = new TreeNode(preorder[sP]);

        // Find the position of the root in inorder traversal
        int rootIndex = mpp[preorder[sP]];
        int numsLeft = rootIndex - sI;

        // Construct the left and right subtrees recursively
        root->left = solve(preorder, sP + 1, sP + numsLeft, inorder, sI, rootIndex - 1, mpp);
        root->right = solve(preorder, sP + numsLeft + 1, eP, inorder, rootIndex + 1, eI, mpp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    }
};

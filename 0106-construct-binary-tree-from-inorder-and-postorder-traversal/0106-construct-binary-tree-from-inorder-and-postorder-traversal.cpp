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
private:
    TreeNode* buildTreeHelper(const vector<int>& inorder, int sI, int eI, const vector<int>& postorder, int &pIndex, unordered_map<int, int>& mpp) {
        // Base condition
        if (sI > eI) return NULL;

        // Create the root node using the current element of postorder traversal
        TreeNode* root = new TreeNode(postorder[pIndex--]);

        // Find the position of the root in inorder traversal
        int rootIndex = mpp[root->val];

        // Recursively construct the right and left subtrees
        // Note: right subtree is constructed first because postorder is being processed from end to start
        root->right = buildTreeHelper(inorder, rootIndex + 1, eI, postorder, pIndex, mpp);
        root->left = buildTreeHelper(inorder, sI, rootIndex - 1, postorder, pIndex, mpp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        int pIndex = postorder.size() - 1; // Start from the end of postorder array
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, pIndex, mpp);
    }
};

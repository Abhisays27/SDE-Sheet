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
    TreeNode* solve(int s,int e,vector<int> arr,int& i){
        if(i>=arr.size()) return NULL;
        if(arr[i]<s || arr[i]>e){
            return NULL;
        }
        TreeNode* root = new TreeNode(arr[i++]);
        root->left=solve(s,root->val,arr,i);
        root->right=solve(root->val,e,arr,i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(INT_MIN,INT_MAX,preorder,i);
    }
};
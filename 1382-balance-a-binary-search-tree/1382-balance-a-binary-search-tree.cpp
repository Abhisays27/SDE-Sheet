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
    void inorder(TreeNode* root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balance(int s,int e,vector<int>& arr){
        if(s>e){
            return NULL;
        }
        int m=(s+e)/2;
        TreeNode* root= new TreeNode(arr[m]);
        root->left=balance(s,m-1,arr);
        root->right=balance(m+1,e,arr);
        return root;

    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return balance(0,arr.size()-1,arr);

    }
};
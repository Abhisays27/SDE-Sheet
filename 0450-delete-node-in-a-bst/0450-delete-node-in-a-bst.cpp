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
public:
  
TreeNode* minVal(TreeNode* root) {
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }
            if(!root->right && root->left){
                TreeNode* left=root->left;
                delete root;
                return left;
            }
            if(root->right && !root->left){
                TreeNode* right=root->right;
                delete root;
                return right;
            }
            if(root->left && root->right){
                root->val=minVal(root->right)->val;
                root->right=deleteNode(root->right,root->val);
                return root;
            }

        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
        return NULL;
    }
};
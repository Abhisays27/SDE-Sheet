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
    void solve(TreeNode* root,int flag, int cnt, int &ans){
        if(root==NULL){
            return;
        }

        ans = max(ans,cnt);

        if(flag==1){
            //iT is coming from right
            solve(root->left,!flag,cnt+1,ans);
            solve(root->right,flag,1,ans);
        }
        else{
            solve(root->right,!flag,cnt+1,ans);
            solve(root->left,flag,1,ans);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans=0;
        if(root==NULL) return ans;

       
        

        solve(root->right,1,1,ans);
        solve(root->left,0,1,ans);

        return ans;
        
    }
};
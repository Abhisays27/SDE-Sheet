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
 // properties we need to solve this
 class info{
 public:
   int maxi; 
   int mini;
   bool isBst;
   int sum ;
 };
info solve(TreeNode*root,int &ans){
    // if root== NULL then simply return the maximum and minimum and the currsum =0
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    // left call
    info left= solve(root->left,ans);
    // right
    info right = solve(root->right,ans);
    info currNode;
    //calculation for the sum of the current Node
    currNode.sum = left.sum +right.sum +root->val;
    //current node ke maximum value is define as
    // maximum of current Nodes val and maximum of right subtree
    currNode.maxi = max(root->val,right.maxi);
    // currNode ke minimum is defines as minimum of roots val and minimum of left subtree
    currNode.mini = min(root->val,left.mini);
    // now condition for being the current node is a bst
    // 1.left and right subtree are also bst 
    //2.roots val lies btw maximum of left subtree ans minimum of right subtree
    if(left.isBst && right.isBst && 
    (root->val>left.maxi && root->val<right.mini)){
        currNode.isBst= true;
    }
    else{
       currNode.isBst = false;
    }
    //if the current node is bst and add that node value also
    if(currNode.isBst){
        ans = max(ans,currNode.sum);
    }
    return currNode;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum =0;
        info temp = solve(root,maxSum);
        return maxSum;
    }
};
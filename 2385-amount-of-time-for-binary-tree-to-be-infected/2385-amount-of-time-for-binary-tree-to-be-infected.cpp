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
    int Burn(TreeNode* root, int& timer, int start){
        if(!root){
            return 0;
        }
        if(root->val==start){
            return -1;
        }
        int left = Burn(root->left,timer,start);
        int right = Burn(root->right,timer,start);
  //agr burn left se hua 
        if(left<0){
            timer = max(timer,right+abs(left));
            return left-1;
        }
  //agr burn right se hua 
        if(right<0){
            timer = max(timer,left+abs(right));
            return right-1;
        }
        else{
            return max(left,right)+1;
        }
    }

    void find(TreeNode* root,int target,TreeNode*& BurnNode){
        if(!root){
            return;
        }
        if(root->val==target){
            BurnNode=root;
            return;
        }
        find(root->left,target,BurnNode);
        find(root->right,target,BurnNode);
    }
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int timer=0;
        Burn(root,timer,start);

        //target ke neeche ka
        TreeNode* BurnNode = NULL;
        find(root,start,BurnNode);
        int high = height(BurnNode)-1;
        return max(high,timer);
        
    }
};
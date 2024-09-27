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
    int burnTree(TreeNode* root, int &timer,int start){

        if(root==NULL){
            return 0;
        }
        if(root->val == start){
            return -1;
        }
        

        int left = burnTree(root->left,timer,start);
        int right = burnTree(root->right,timer,start);

        if(left<0){
            timer = max(timer,abs(left) + right);
            return left-1;
        }

        if(right<0){
            timer = max(timer, abs(right) + left);
            return right - 1;
        }
        else{
             return max(left,right)+1;
        }

        


    }


    void findStart(TreeNode* root, int start,TreeNode* &startNode){
        if(root==NULL) {
            return;
        }
        if (root->val==start){
            startNode = root;
            return ;
        }
        
        findStart(root->left,start,startNode);
        findStart(root->right,start,startNode);
        
    }

    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left = findHeight(root->left);
        int right = findHeight(root->right);
        return max(left,right) + 1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
      
     TreeNode* startNode = NULL;
      findStart(root,start,startNode);
       
        
       int subTreeHeight = findHeight(startNode);
       int aboveTime = 0;
       burnTree(root,aboveTime,start);


       return max(subTreeHeight-1,aboveTime);


        
    }
};
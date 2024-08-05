/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void makeGraph(TreeNode* &root,unordered_map<int,vector<int>> &adjLst){
        if(root==NULL) return;

        if(root->left!=NULL){
            adjLst[root->left->val].push_back(root->val);
             adjLst[root->val].push_back(root->left->val);

        } 
        if(root->right!=NULL){
            adjLst[root->right->val].push_back(root->val);
             adjLst[root->val].push_back(root->right->val);

        }
        makeGraph(root->left,adjLst);
        makeGraph(root->right,adjLst);
    }

    void dfs(int node,unordered_map<int,vector<int>> &adjLst,vector<int> &ans,unordered_map<int,bool> &vis,int cnt,int k){

        if(cnt==k){
            ans.push_back(node);
            return;
        }
        vis[node]=false;

        for(auto it : adjLst[node]){

            if(vis[it]==true){
                dfs(it,adjLst,ans,vis,cnt+1,k);
            }
        }



    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<int,vector<int>> adjLst;
        makeGraph(root,adjLst);
        int tgt = target->val;

        vector<int> ans;
        unordered_map<int,bool> mpp;
        for(auto it : adjLst){
            mpp[it.first]=true;
        }
        int cnt=0;
        dfs(tgt,adjLst,ans,mpp,cnt,k);
        return ans;

    }
};
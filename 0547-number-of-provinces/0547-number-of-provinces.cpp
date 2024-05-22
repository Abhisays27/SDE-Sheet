class Solution {
    private:
    void dfs(int node,vector<int> &vis, vector<int> adjlst[]){
        vis[node]=1;

        for(auto it: adjlst[node]){
            if(!vis[it]){
                dfs(it,vis,adjlst);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
         //creating adj list
        vector<int> adjlst[V];
         for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlst[i].push_back(j);
                     adjlst[j].push_back(i);

                }
            }
         }

     vector<int> vis(V,0);
         int cnt=0;

         for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjlst);

            }
         }
         return cnt;
        
    }
};
class Solution {
private:
    bool dfs(int node,vector<int> &vis,vector<vector<int>>& graph,int col){
        vis[node]=col;

        for(auto it: graph[node]){
            if(vis[it]==-1){
                if((dfs(it,vis,graph,!col))==false) return false;
            }
            else if(vis[it]==col) return false;
        }
     return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //0- first color
        //1-second colour
        int col=0;
        int V=graph.size();
        vector<int> vis(V,-1);

        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if((dfs(i,vis,graph,col))==false) return false;
            }
        }
     
        return true;
    }
};
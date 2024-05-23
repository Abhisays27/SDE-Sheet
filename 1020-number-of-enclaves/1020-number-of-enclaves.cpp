class Solution {
    private:
     void dfs(int row,int col, vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                dfs(nrow,ncol,vis,grid);
            }
        }


    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

 // Start DFS from all 'O's on the boundary
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0) {
                dfs(i, 0, vis, grid);
            }
            if (grid[i][m-1] == 1 && vis[i][m-1] == 0) {
                dfs(i, m-1, vis, grid);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && vis[0][j] == 0) {
                dfs(0, j, vis, grid);
            }
            if (grid[n-1][j] == 1 && vis[n-1][j] == 0) {
                dfs(n-1, j, vis, grid);
            }
        }

        //conected components
        int cnt=0;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;

     
              }
            }
        }
       return cnt;
        
    }
};
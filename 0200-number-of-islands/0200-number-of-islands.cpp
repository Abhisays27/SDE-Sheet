class Solution {
    void dfs(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='0';
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();

       
        
        for(int k=0;k<4;k++){
      int nrow = i + drow[k];
    int ncol = j + dcol[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1')
           {
                dfs(nrow,ncol,grid);
            }

        }

        

        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
        
    }
};
class Solution {

    int dfs(int i,int j, int n,int m, vector<vector<int>>& grid,int &perimeter){
        grid[i][j]=-1;
     
        

        int dcol[]={1,0,-1,0};
        int drow[]={0,-1,0,1};

        for(int k=0;k<4;k++){
            int nrow= i + drow[k];
            int ncol= j + dcol[k];
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]==0){
               
               perimeter++;
            }

          else if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
               
                dfs(nrow,ncol,n,m,grid,perimeter);
            }
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
         int n=grid.size();
       int m=grid[0].size();
       int perimeter=0;


       //itreate the whole matrix

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                
               dfs(i,j,n,m,grid,perimeter); 
            }
           
        }
       }

       return perimeter;

    }
};
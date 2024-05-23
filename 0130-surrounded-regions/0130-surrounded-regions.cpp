class Solution {
private:
    void dfs(int row,int col, vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                dfs(nrow,ncol,vis,board);
            }
        }


    }
        
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));


  // Start DFS from all 'O's on the boundary
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && vis[i][0] == 0) {
                dfs(i, 0, vis, board);
            }
            if (board[i][m-1] == 'O' && vis[i][m-1] == 0) {
                dfs(i, m-1, vis, board);
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && vis[0][j] == 0) {
                dfs(0, j, vis, board);
            }
            if (board[n-1][j] == 'O' && vis[n-1][j] == 0) {
                dfs(n-1, j, vis, board);
            }
        }


// swapping inner elemts with X
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
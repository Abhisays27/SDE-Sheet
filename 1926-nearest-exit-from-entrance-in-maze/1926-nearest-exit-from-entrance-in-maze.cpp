class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = entrance[0];
        int col = entrance[1];
        int n = maze.size();
        int m = maze[0].size();

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        queue<pair<pair<int, int>, int>> q;
        q.push({{row, col}, 0});
        maze[row][col] = '+';

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int cnt = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && maze[nrow][ncol] == '.') {
                    
                    if ((nrow == 0 || ncol == 0 || nrow == n - 1 || ncol == m - 1) && !(nrow == row && ncol == col)) {
                        return cnt + 1;
                    }

                    
                    maze[nrow][ncol] = '+';
                    q.push({{nrow, ncol}, cnt + 1});
                }
            }
        }

        return -1;
    }
};

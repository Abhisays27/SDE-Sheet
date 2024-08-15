#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';  
        }
        
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j] - '0';  
        }

        int maxSide = 0;

        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') {
                    int left = dp[i][j-1];
                    int up = dp[i-1][j];
                    int diag = dp[i-1][j-1];

                    dp[i][j] = 1 + min({left, up, diag});
                    maxSide = max(maxSide, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            maxSide = max(maxSide, dp[i][0]);
        }

        for (int j = 0; j < m; j++) {
            maxSide = max(maxSide, dp[0][j]);
        }

        return maxSide * maxSide;
    }
};

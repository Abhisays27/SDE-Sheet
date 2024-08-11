class Solution {
public:
    void gameOfLife(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;

                for (int k = 0; k < 8; k++) {
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];

                    if (nrow >= 0 && ncol < m && nrow < n && ncol >= 0) {
                        if (nums[nrow][ncol] == 1 || nums[nrow][ncol] == 2) { 
                            cnt++;
                        }
                    }
                }

                if (nums[i][j] == 1) {
                    if (cnt < 2 || cnt > 3) {
                        nums[i][j] = 2;
                    }
                } else {
                    if (cnt == 3) {
                        nums[i][j] = 3; 
                    }
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 2) {
                    nums[i][j] = 0;
                } else if (nums[i][j] == 3) {
                    nums[i][j] = 1; 
                }
            }
        }
    }
};

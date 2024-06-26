class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> ans(n,vector<int>(n));
       

        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int cnt=1;

        while (left <= right && top <= bottom) {
            //------>

            for (int i = left; i <= right; i++) {
                ans[top][i]=cnt++;
            }
            top++;


            // right to bottom

            for (int i = top; i <= bottom; i++) {
                 ans[i][right]=cnt++;
            }
            right--;

            // bottom right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i]=cnt++;
                }
                bottom--;
            }


            

            // from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                   ans[i][left] =cnt++;
                }
                left++;
            }
        }

        return ans;
        
    }
};
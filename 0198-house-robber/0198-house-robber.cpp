
class Solution {
    // int solve(vector<int>& nums, int n, vector<int>& memo) {
    //     if (n <= 0) return 0;
    //     if (memo[n] != -1) return memo[n];

    //     int steal = nums[n - 1] + solve(nums, n - 2, memo);
    //     int skip = solve(nums, n - 1, memo);

    //     memo[n] = max(steal, skip);
    //     return memo[n];
    // }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<n+1;i++){

            int steal = nums[i-1] + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(steal,skip);

        }

        return dp[n];       
    }
};
class Solution {
    int solve1(int s,  vector<int>& nums){
        int n = nums.size()-1;
        vector<int> dp(n + 1, -1);

        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<n+1;i++){

            int steal = nums[i-1+s] + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(steal,skip);

        }

        return dp[n]; 
    }

    int solve2(int s, vector<int>& nums){
        int n = nums.size()-1;
        vector<int> dp(n + 1, -1);

        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<n+1;i++){

            int steal = nums[i-1+s] + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(steal,skip);

        }

        return dp[n]; 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

         if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int first = solve1(0,nums);
        int sec = solve2(1,nums);

        return max(first,sec);
              
        
    }
};
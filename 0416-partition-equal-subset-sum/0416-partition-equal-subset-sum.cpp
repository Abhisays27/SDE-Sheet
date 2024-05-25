class Solution {
public:
    bool canPartition(vector<int>& nums) {
     int n=nums.size();
     int sum=0;
     for(int i=0;i<n;i++){
       sum+=nums[i];
     }
     int W=sum/2;
     if(sum%2!=0) return false; // If sum is odd, we can't partition it into two equal subsets
     
   
      vector<vector<bool>> dp(n + 1, vector<bool>(W + 1, false));
  
     for(int i = 0; i <= n; i++) {
            dp[i][0] = true; // Initializing the first column to true
        }
  

     


     
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){

                if(nums[i-1]<=j){
                    dp[i][j]= dp[i-1][j-nums[i-1]]  || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][W];

    
        
    }
};
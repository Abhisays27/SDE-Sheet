class Solution {
    int dp[1000][1000];
public:
    int coinChange(vector<int>& coins, int amount) {
        int W = amount;
        int n=coins.size();
         
        int dp[n+1][W+1];
        memset(dp,0,sizeof(dp));

        for(int j=0;j<=W;j++){
            dp[0][j]=INT_MAX-1;
        }
        for(int j=1;j<=W;j++){
            if(j%coins[0]==0) dp[1][j]=j/coins[0];
            else dp[1][j]=INT_MAX-1;
        }

        for(int i=2;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]], dp[i-1][j]); //agr include hua
                }
                else dp[i][j]=dp[i-1][j];  //agr include ni hua
            }
        }

        if(dp[n][W]==INT_MAX-1) return -1;
        else return dp[n][W];

        
    }
};
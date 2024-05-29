class Solution {
    int dp[1001][1001];
public:
    int minInsertions(string s) {
    string b = s;
    reverse(b.begin(),b.end());
        int n=s.size();
        int m = b.length();
        
        
        
        dp[n+1][m+1];

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(dp[n][m]==n) return 0;
        else return n-dp[n][m];
    }
};
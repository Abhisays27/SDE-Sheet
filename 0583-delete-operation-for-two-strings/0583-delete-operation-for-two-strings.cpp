class Solution {
 int dp[1001][1001];
public:
    int minDistance(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        dp[n+1][m+1];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcs=dp[n][m];
        int s1=text1.size()-lcs;
        int s2=text2.size()-lcs;

        return s1+s2;
    }
};
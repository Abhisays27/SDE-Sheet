class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_left=prices[0];
        int max_pro=0;

        for(int i=1;i<n;i++){
            if(min_left>prices[i]){
                min_left=prices[i];
            }
            max_pro=max(max_pro,prices[i]-min_left);
        }
        return max_pro;
        
    }
};
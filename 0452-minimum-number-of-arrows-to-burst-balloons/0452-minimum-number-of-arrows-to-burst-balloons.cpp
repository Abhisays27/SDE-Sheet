class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        
        int n = nums.size();
    
     sort(nums.begin(),nums.end());
        
        int sP=nums[0][0];
        int eP=nums[0][1];
        int cnt=1;

        for(int i=1;i<n;i++){

            if(eP < nums[i][0]){
                cnt++;
                sP = nums[i][0];
                eP = nums[i][1];
            }
            else{
               sP = max(sP,nums[i][0]);
               eP = min(eP,nums[i][1]);
            }
        }

        return cnt;
    }
};
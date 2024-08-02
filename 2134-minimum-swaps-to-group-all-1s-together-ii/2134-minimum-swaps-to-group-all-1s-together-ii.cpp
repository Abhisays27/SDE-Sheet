class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int swaps = INT_MAX;
        int cnt =0;

        int k = 0;
        
      

        for(auto it : nums){
            if(it==1) k++;
        }
          // If there are no 1s, no swaps needed
        if (k == 0) return 0;

        int i=0;
        int j=0;
        while(j<n+k){

            if(nums[j%n]==1) cnt++;

            if(j-i+1<k) {
                j++;
            }
            if(j-i+1==k){
                swaps = min(swaps,k-cnt);
                if(nums[i%n]==1) cnt--;
                i++;
                j++;
            }




        }
        return swaps;
    }
};
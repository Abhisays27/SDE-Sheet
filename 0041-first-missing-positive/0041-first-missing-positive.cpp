class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        //1 ---> n+1

        for(int i=0;i<n;i++){
            int el = nums[i]; //3
              // 2

            if(el>0 && el<=n){
                int pos = el - 1;

                if(nums[pos]!=el){
                swap(nums[i],nums[pos]);
                i--;
            }


            }

            
        }

        for(int i=0;i<n;i++){
            int ind = i+1;
            if(ind!=nums[i]){
                return ind;
            }
        }
        return n+1;
        
    }
};
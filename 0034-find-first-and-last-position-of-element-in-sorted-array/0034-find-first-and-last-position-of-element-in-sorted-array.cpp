class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n=nums.size();
        int s=0;
        int e=n-1;
        int res1=-1;
        int res2=-1;
    
    //lower bound
        while(s<=e){
           int mid=s +(e-s)/2;

            if(target==nums[mid]){
                res1=mid;
                e = mid-1;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
         // reset s and e for upper bound search
        s = 0;
        e = n - 1;

        //upper bound
        while(s<=e){
           int mid=s +(e-s)/2;

            if(target==nums[mid]){
                res2=mid;
                s= mid+1;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return {res1,res2};
        
    }
};
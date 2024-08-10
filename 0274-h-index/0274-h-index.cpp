class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int s = 0;
        int l = nums.size();
        int e = l - 1;

        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;

          
            if (l - mid <= nums[mid]) {
                ans = l - mid;  
                e = mid - 1;    
            } else {
                s = mid + 1;    
            }
        }

        return ans;
    }
};

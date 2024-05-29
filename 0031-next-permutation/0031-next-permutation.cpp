class Solution {
public:
    void nextPermutation(vector<int>& nums) {

         int n = nums.size();
        int pivot = -1;

        // Find the largest index `pivot` such that `nums[pivot] < nums[pivot + 1]`
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                pivot = i - 1;
                break;
            }
        }

        if (pivot == -1) {
            // If no such pivot exists, reverse the whole array
            reverse(nums.begin(), nums.end());
        } else {
            // Find the largest index `i` such that `nums[i] > nums[pivot]`
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[pivot], nums[i]);
                    break;
                }
            }
            // Reverse the subarray from `pivot + 1` to the end
            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};
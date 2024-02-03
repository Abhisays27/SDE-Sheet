#include <vector>
#include <algorithm> // for std::sort

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        // If no duplicate is found
        return -1; // or any other appropriate value indicating no duplicate
    }
};
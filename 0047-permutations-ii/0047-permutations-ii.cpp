class Solution {
public:
    void func(int index, vector<vector<int>>& ans, vector<int>& nums) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
           if (i != index && nums[i] == nums[index]) {
                continue;
            }
            swap(nums[index], nums[i]);
            func(index + 1, ans, nums);
            swap(nums[index], nums[i]); // Backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the numbers to handle duplicates
        vector<vector<int>> ans;
        func(0, ans, nums);
        return ans;
    }
};

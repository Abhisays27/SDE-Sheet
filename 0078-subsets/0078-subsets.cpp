class Solution {
   void func(int index, vector<int>& nums, vector<int>& output, vector<vector<int>>& ans) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        
        // Pick the current element
        output.push_back(nums[index]);
        func(index + 1, nums, output, ans);
        output.pop_back();
        
        // Skip duplicates
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        
        // Not pick the current element
        func(index + 1, nums, output, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
        func(0, nums, output, ans);
        return ans;
        
    }
};
class Solution {
    void func(int index,vector<int> nums,vector<int> output,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
         //not pick
        func(index+1,nums,output,ans);
        //pick
        output.push_back(nums[index]);
        func(index+1,nums,output,ans);
        
        
        

       

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        func(index,nums,output,ans);
        return ans;
        
    }
};
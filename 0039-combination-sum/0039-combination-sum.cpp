class Solution {
    void func(int index, vector<vector<int>>& ans,vector<int>& ds,vector<int>& arr, int target){
        if(index==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //pick
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            func(index,ans,ds,arr,target-arr[index]);
            ds.pop_back();
        }
        func(index+1,ans,ds,arr,target);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,ans,ds,candidates,target);
        return ans;
        
    }
};
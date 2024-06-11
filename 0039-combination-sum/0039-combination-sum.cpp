class Solution {
    private:
    void solve(vector<int> arr, vector<int>& ds,vector<vector<int>> &ans,int target ,int index){
        if(index>=arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //pick element 
        if(target>=arr[index]){
            ds.push_back(arr[index]);
            solve(arr,ds,ans,target-arr[index],index);
            ds.pop_back();
        }
        //not pick
        solve(arr,ds,ans,target,index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> ds;
        solve(candidates,ds,ans,target,0);
        return ans;
        
    }
};
class Solution {

    void solve(int idx, int n, int k, vector<vector<int>> &ans, vector<int> &temp){

        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(idx>n){
            return;
        }

        temp.push_back(idx);
        solve(idx+1,n,k-1,ans,temp);
        temp.pop_back();
        solve(idx+1,n,k,ans,temp);

        



    }
     
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;  

        solve(1, n, k, ans, temp);

        return ans;
    }
};

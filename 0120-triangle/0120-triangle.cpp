class Solution {
    int  solve(int i, int j, vector<vector<int>>& nums){

        if(i==nums.size()-1){
            return nums[i][j];
        }

        return nums[i][j] + min(solve(i+1,j,nums),solve(i+1,j+1,nums));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
       
       int ans = 0;
       int i=0;
       int j=0;
       return solve(i,j,triangle);
     
        
        
        
    }
};
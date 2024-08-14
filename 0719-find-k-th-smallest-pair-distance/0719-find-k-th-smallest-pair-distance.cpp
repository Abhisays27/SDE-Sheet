class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        int n = nums.size();
      
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 int temp = abs(nums[j] - nums[i]);
            

            pq.push(temp);

            }
           
           
        
        }

        for(int i=1;i<=k-1;i++){
            pq.pop();
        }

        return pq.top();


        
    }
};
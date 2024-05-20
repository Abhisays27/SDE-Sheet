class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;

        for(auto it: nums){
            m[it]++;
        }

        for(auto it: m){
            pq.push({it.second,it.first});

        }
        vector<int> ans;
        while(k--){
            auto val = pq.top();
            pq.pop();
            ans.push_back(val.second);
        }
        return ans;
        
    }
};
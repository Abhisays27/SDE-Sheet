class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int i=0;
        int k=st.size();
        for(auto it: st){
            nums[i]=it;
            i++;
        }
        return k;
        
    }
};
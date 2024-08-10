class RandomizedSet {
    unordered_map<int,int> st;
    vector<int> nums;
public:
    RandomizedSet() {
        
        
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end()){
            nums.push_back(val);
            int i = nums.size()-1;
            st[val]=i;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            st.erase(val);
            int j = st[val];
            swap(nums[j],nums[nums.size()-1]);
            nums.pop_back();

            return true;
        }
        else{
            return false;
        }
        
    }
    
    int getRandom() {
       
       return nums[rand() % (nums.size())];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
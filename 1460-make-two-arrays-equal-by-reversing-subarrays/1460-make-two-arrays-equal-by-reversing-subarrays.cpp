#include <vector>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (arr.size() != target.size()) return false;

        unordered_multiset<int> st;
        for (auto it : target) {
            st.insert(it);
        }

        for (auto it : arr) {
            auto pos = st.find(it);
            if (pos != st.end()) {
                st.erase(pos); // Erase only one instance
            } else {
                return false;
            }
        }

        return true;
    }
};

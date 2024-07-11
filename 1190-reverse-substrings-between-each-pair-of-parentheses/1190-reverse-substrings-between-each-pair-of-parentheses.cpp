class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int start = st.top();
                st.pop();
                reverse(s.begin() + start + 1, s.begin() + i); 
                s.erase(i, 1); 
                s.erase(start, 1); 
                i -= 2; 
            }
        }

        return s;
    }
};

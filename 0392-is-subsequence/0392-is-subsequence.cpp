class Solution {
public:
    bool isSubsequence(string s, string t) {
       
        int n=s.size();
        int m=t.size();
        int i=0;
        for (int j = 0; j < m; j++) {  // Pointer for string t
            if (i < n && s[i] == t[j]) {
                i++;
            }
        }
        
        // Check if all characters in s were found in t
        return (i == n);
        
    }
};
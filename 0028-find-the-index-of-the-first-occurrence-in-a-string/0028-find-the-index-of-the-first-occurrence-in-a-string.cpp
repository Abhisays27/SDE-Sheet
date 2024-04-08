class Solution {
public:
    int strStr(string haystack, string needle) {
        char ch = needle[0];
        int n = needle.size();
        int i = 0;
        while (i <= haystack.size() ) {
            if (ch == haystack[i]) {
                // Check if the substring matches
                if (needle == haystack.substr(i, n)) {
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};

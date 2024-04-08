#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) return 0; // needle is empty
        
        // Constructing the prefix table for the needle string
        vector<int> prefix(n);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = prefix[j - 1];
            }
            if (needle[i] == needle[j]) {
                prefix[i] = ++j;
            }
        }
        
        // Performing the KMP search
        j = 0;
        for (int i = 0; i < m; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = prefix[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == n) {
                return i - n + 1; // Found the needle at index i
            }
        }
        
        return -1; // Needle not found
    }
};

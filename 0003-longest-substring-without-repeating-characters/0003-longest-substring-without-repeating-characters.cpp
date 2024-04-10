class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         map<char, int> mpp;

    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    
    while (right < n) {
        // If the character at s[right] is found in the map,
        // update the left pointer to the next position after the last occurrence of s[right]
        if (mpp.find(s[right]) != mpp.end())
            left = max(mpp[s[right]] + 1, left);

        // Update the last occurrence position of the current character
        mpp[s[right]] = right;

        // Update the length of the longest substring
        len = max(len, right - left + 1);

        // Move the right pointer to the next position
        right++;
    }
    
    return len;
    }
};
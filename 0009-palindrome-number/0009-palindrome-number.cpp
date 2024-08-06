class Solution {
public:
    bool isPalindrome(int x) {
        // if (x < 0) {
        //     return false;
        // }

        // long long reversed = 0;
        // long long temp = x;

        // while (temp != 0) {
        //     int digit = temp % 10;
        //     reversed = reversed * 10 + digit;
        //     temp /= 10;
        // }

        // return (reversed == x);
        string s = to_string(x);

        int i=0;
        int j=s.size()-1;

        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }

        return true;
    }
};
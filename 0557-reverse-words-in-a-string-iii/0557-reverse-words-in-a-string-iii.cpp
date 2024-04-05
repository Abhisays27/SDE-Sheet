class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int l=0;
        int r=0;

        for(int i=0;i<n;i++){
             if (s[i] == ' ') {
                std::reverse(s.begin() + l, s.begin() + r);
                l = i + 1; // Move l to the next position after space
            } else {
                r = i + 1; // Increment r if not a space
            }
          

        }
        //last
          reverse(s.begin() + l, s.begin() + r);
        return s;

    }
};
class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        unordered_map<char, int> mpp;

        for (auto it : t) {
            mpp[it]++;
        }

        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        int cnt = t.size();
        int s_index=0;

        while (j < s.size()) {

            char ch = s[j];
            //expanding the window
            if (mpp.find(ch) != mpp.end()) {
                if (mpp[ch] > 0) {
                    cnt--;
                }
                mpp[ch]--;
            }
            

            //shrinking

            while(cnt==0){
                
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    s_index=i;
                }

            if (mpp.find(s[i]) != mpp.end()) {
                mpp[s[i]]++;
                if (mpp[s[i]] > 0) {
                    cnt++;
                }
              
            }
            i++;

            }
            j++;
        }
        

        if(minLen==INT_MAX) return "";
        else return s.substr(s_index,minLen);
    }
};
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> st;
        func(0,s,ans,st);
        return ans;
        
    }
    void func(int index,string s , vector<vector<string>>& ans,vector<string>& st){
        if(index>=s.size()){
            ans.push_back(st);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                st.push_back(s.substr(index,i-index+1));
                func(i+1,s,ans,st);
                st.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int st,int e){
         while (st <= e) {
        if (s[st++] != s[e--]) 
            return false;
    }
    return true;

    }
};
class Solution {

    void solve(string &digits, int ind, vector<string> &mpp,  vector<string> &ans, string &temp){

        if(ind>= digits.size()){
            ans.push_back(temp);
            return;
        }

        int num = digits[ind] - '0';
        string val = mpp[num];

        for(int i=0;i<val.size();i++){
            temp.push_back(val[i]);
            solve(digits,ind+1,mpp,ans,temp);
            temp.pop_back();
        }
    }
   

public:
    vector<string> letterCombinations(string digits) {
        

        vector<string> mpp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int ind = 0;
        

        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string temp = "";

        solve(digits, ind, mpp, ans, temp);
        return ans;
        
    }
};
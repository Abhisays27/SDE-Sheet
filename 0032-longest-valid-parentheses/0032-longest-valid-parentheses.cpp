class Solution {
public:
    int longestValidParentheses(string s) {

        int l=0;
        int r=0;
        int maxi = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                l++;
            }
            else{
                r++;
            }

            if(l==r){
                maxi = max(maxi,2*l);
            }
            else if(r>l){
                l=0;
                r=0;
            }
        }

        l=0;
         r=0;

         for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                l++;
            }
            else{
                r++;
            }

            if(l==r){
                maxi = max(maxi,2*l);
            }
            else if(l>r){
                l=0;
                r=0;
            }
        }
        
        return maxi;
    }
};
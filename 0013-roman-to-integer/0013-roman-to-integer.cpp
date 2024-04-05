class Solution {
    int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
public:
    int romanToInt(string s) {
        int n=s.size();
        int res=value(s[n-1]);
        for(int i=s.size()-2;i>=0;i--){

            if(value(s[i])<value(s[i+1])){
                res-=value(s[i]);
            }
            else{
                res+=value(s[i]);
            }

        }
        return res;
        
    }
};
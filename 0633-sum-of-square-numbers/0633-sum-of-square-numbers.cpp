class Solution {
public:
    bool judgeSquareSum(int c) {
        int last = sqrt(c);

        int s=0;
        int e=last;

        while(s<=e){
            long long a = s*s;
            long long b=e*e;
            if(a+b==c){
                return true;
            }

            if(a+b>c){
                e--;
            }
            else if(a+b<c){
                s++;
            }
        }
        return false;
    }
};
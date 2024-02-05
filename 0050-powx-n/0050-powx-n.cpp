class Solution {
public:
    double myPow(double x, int n) {
        double result=1;
        int temp=abs(n);
        while(temp>0){

            if((temp & 1)==1) //if n is odd
            {
                result=result*x;
            }
            x=x*x;
            temp=temp>>1;
            
        }
     

        return (n>0)?result:(1/result);
        
    }
};
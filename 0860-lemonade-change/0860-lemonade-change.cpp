class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int left5=0;
        int left10=0;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                left5++;
            }
            if(bills[i]==10){

                if(left5>=1){
                left10++;
                left5--;

                }
                else{
                    return false;
                }
                
            }
            if(bills[i]==20){

                if(left5>=2 && left10>=1){
                    left5-=2;
                    left10--;
                }
               else  if(left5>=3){
                    left5-=3;
                }
                
                else{
                    return false;
                }
            }
        }

        return true;
        
    }
};
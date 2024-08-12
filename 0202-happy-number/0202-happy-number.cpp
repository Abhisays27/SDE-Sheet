class Solution {
public:
    bool isHappy(int n) {

     string k = to_string(n);

     while(k.size()>1){
        int sum=0;

        for(int i=0;i<k.size();i++){
            int a = k[i]-'0';
            sum+=a*a;

        }
        k = to_string(sum);
     }

     int num = stoi(k);

     if(num==1) return true;
     else return false;
        
    }
};
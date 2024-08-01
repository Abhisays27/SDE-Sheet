class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;

        for(auto it : details){
            string temp = "";
            for(int i=11;i<=12;i++){
                temp+=it[i];

            }
            int num = stoi(temp);
            if(num>60) cnt++;
        }

        return cnt;
        
    }
};
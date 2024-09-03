class Solution {
public:
    int getLucky(string s, int k) {
       
        string str = "";
        for (char ch : s) {
            int value = ch - 'a' + 1;  
            str += to_string(value);
        }

      
        for (int i = 0; i < k; i++) {
            int num = 0;
            for (char ch : str) {
                num += ch - '0';
            }
            str = to_string(num);  
        }

       
        return stoi(str); 
    }
};

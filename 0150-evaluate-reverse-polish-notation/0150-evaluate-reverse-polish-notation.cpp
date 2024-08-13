class Solution {
public:
    int evalRPN(vector<string>& tokens) {

       int n=tokens.size();

       stack<int> st;

       for(int i=0;i<n;i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" | tokens[i] == "/"){
            int num1= st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            int temp=0;

            if(tokens[i]=="+") {
               temp= num2+num1;

            }
            
           else if(tokens[i]=="-") {
               temp= num2-num1;

            }
            else if(tokens[i]=="*") {
               temp= num2*num1;

            }
            else{
                temp=num2/num1;
            }
            st.push(temp);
        }
        else{
            st.push(stoi(tokens[i]));
        }
       }

       return st.top();
        
    }
};
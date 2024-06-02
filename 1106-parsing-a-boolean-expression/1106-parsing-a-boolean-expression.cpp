class Solution {
    bool sol(int &i,string &s){

        char exp=s[i];// store which expression is present in firstly
        bool tPresent=0,fPresent=0;// declare two variables for check if true is present and false is present

        i+=2;//it skips '(' and move to expression inside it

        while(s[i-1]!=')'){//if we skip closing bracket then it break 

            if(s[i]=='t')tPresent=true;

            else if(s[i]=='f')fPresent=true;

            else{//if any other operator with another brackets is present
                bool rec=sol(i,s);// do recursive call abd calulate the value
                if(rec)tPresent=true;
                else fPresent=true;
            }
            i+=2;// again skip ','
        }
        i--;// go to index after this ')'
 
        if(exp=='|')return tPresent;// if true present return true
        if(exp=='&')return !fPresent;// if false present return false
        
        //if '!' is there
        if(tPresent)return false;
        return true;
    }
public:
    bool parseBoolExpr(string expression) {
        int i=0;
        return sol(i,expression);
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> st;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                char num = board[i][j];
                if(board[i][j]!='.'){
                    string row = to_string(num)+"row"+to_string(i);
                     string col = to_string(num)+"col"+to_string(j);
                     string box = to_string(num)+"box"+to_string(i/3)+to_string(j/3);

                     if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end()) return false;

                     st.insert(row);
                     st.insert(col);
                     st.insert(box);
                }
            }
        }
        return true;
        
    }
};
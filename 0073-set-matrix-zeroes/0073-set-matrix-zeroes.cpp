class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool setRow= false;
        bool setCol=false;
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    if(i==0) setRow=true;
                    
                    if(j==0)  setCol=true;
                    
              matrix[0][j]=0;
                matrix[i][0]=0;
                }
            
            }
        }
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                 if(matrix[0][j]==0 || matrix[i][0]==0){ // Fixed the condition here
            matrix[i][j]=0;
        }

            }
        }
        if(setRow){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }
         if(setCol){
            for(int j=0;j<row;j++){
                matrix[j][0]=0;
            }
        }
    }
};
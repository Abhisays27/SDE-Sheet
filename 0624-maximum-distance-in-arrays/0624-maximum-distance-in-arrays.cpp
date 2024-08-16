class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int n = arrays.size();

        int k=0;
        int mini=INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<arrays[i].size();j++){
                if(arrays[i][j]<mini){
                    mini = arrays[i][j];
                    k=i;
                }

            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<arrays[i].size();j++){
                if( i!=k && arrays[i][j]>maxi ){
                    maxi = arrays[i][j];
                    
                }

            }
        }

        return abs(maxi-mini);
        
    }
};
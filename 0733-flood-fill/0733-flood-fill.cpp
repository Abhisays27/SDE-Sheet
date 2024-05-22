class Solution {
private:
      void dfs(int sr, int sc, int originalColor, int newColor, vector<vector<int>>& image) {
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        int n = image.size();
        int m = image[0].size();
        
        image[sr][sc] = newColor;

        for (int i = 0; i < 4; i++) {
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == originalColor) {
                dfs(nrow, ncol, originalColor, newColor, image);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
     
     int originalColor = image[sr][sc];
        if (originalColor != color) { // To prevent infinite recursion
            dfs(sr, sc, originalColor, color, image);
        }
       
        return image;
    }
};
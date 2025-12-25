class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = -1e8, down = -1e8;
                int right = -1e8, left = -1e8;
                
                if(i - 1 >= 0) up = mat[i-1][j];
                if(j - 1 >= 0) left = mat[i][j-1];
                if(i + 1 < n) down = mat[i+1][j];
                if(j + 1 < m) right = mat[i][j+1];
                
                if(mat[i][j] >= up && mat[i][j] >= down
                && mat[i][j] >= left && mat[i][j] >= right){
                    return {i, j};
                }
            }
        }
        
        return {-1, -1};  
    }
};

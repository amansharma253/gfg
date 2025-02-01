//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int n,m;
    int dir[5] = {0,1,0,-1,0};
    bool search(vector<vector<char>>& mat, string& word,int i,int j,int k,vector<vector<bool>>&vis){
        if(k==word.size())return true;
        vis[i][j] = 1;
        for(int p=0;p<4;p++){
            int i_ = dir[p] + i;
            int j_ = dir[p+1] + j;
            if(i_ < n && i_>=0 && j_<m && j_>=0 && vis[i_][j_]!=1 && mat[i_][j_]==word[k]){
                    
                if(search(mat,word,i_,j_,k+1,vis))return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        n = mat.size();
        m = mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == word[0]){
                    if(search(mat,word,i,j,1,vis))return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
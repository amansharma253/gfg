class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int pos = 0;
        int i=0, j=0, n = a.size(), m = b.size();
        
        for(int x=0; x<k-1; ++x){
            if(i<n && j<m){
                if(a[i] < b[j]) i++;
                else j++;
            }
            else if(i<n) i++;
            else j++;
        }
        
        int x = INT_MAX, y = INT_MAX;
        if(i<n) x = a[i];
        if(j<m) y = b[j];
        
        return min(x, y);
    }
};
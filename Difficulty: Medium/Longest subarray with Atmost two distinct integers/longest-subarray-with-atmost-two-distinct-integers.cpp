class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int window = 0;
        
        // repeating streak current element
        int streak = 0;
        
        // represent current and previous distinct elements
        int curr = 0;
        int prev= 0;
        
        // store the max length
        int ans = 0;
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == curr){
                window++;
                streak++;
            }
            else if(arr[i] == prev){
                window++;
                streak=1;
                prev = curr;
            }
            else{
                window = streak+1;
                streak = 1;
                prev = curr; // storing the previous repeating element
            }
            if(window>ans)ans=window;
            curr = arr[i];
        }
        
        return ans;
    }
};
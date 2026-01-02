class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = 0;
        int p0 = i;
        int p2 = n-1;
        
        while(i<=p2){
            bool flag = false;
            while(arr[p2]==2){
                p2--;
            }
            
            while(arr[p0]==0){
                p0++;
            }
            
            if(i<p0)i=p0;
            
            if(i>p2)break;
            
            if(arr[i]==0){
                swap(arr[i],arr[p0]);
            }
            
            else if(arr[i]==2){
                swap(arr[i],arr[p2]);
                flag = true;
            }
            if(!flag)i++;}
    }
};
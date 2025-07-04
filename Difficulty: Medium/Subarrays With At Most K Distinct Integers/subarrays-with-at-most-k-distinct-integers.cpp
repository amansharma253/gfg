class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
      int n=arr.size();
        int i=0, j=0, ans=0, cnt=0;
        unordered_map<int, int>mp;
        
        for(; j<n; j++){
            if(mp.find(arr[j])==mp.end()) cnt++;
            mp[arr[j]]++;
            for(; i<n && cnt>k; i++){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                    cnt--;
                }
            }
            ans+=(j-i+1);
        }
        
        return ans;  
    }
};
class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.length();
        unordered_map<int,int>mp;
        int result=0,i=0,j=0;
        while(j<n)
        {
            mp[s[j]]++;
            while((j-i+1)>k || mp.size()>=k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(j-i+1==k)
            {
                if(mp.size()==k-1)
                {
                    result++;
                }
            }
            j++;
        }
        return result;
    }
};
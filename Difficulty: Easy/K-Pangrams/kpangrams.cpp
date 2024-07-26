//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:

    bool kPangram(string str, int k) {
        unordered_map<char,int> m;
        int extra=0;
        
        // calculate the characters present in excess
        for(int i=0;i<str.size();i++)
        {
            if(!isalpha(str[i]))
            {
                continue;
            }
            if(m[str[i]]==1)
            {
                extra++;
            }
            else{
                m[str[i]]=1;
            }
        }
        
        // calculate the total characters brought in 
        int t=0;
        for(char ch='a';ch<='z';ch++)
        {
            if(extra==0)
            {
                break;
            }
            
            if(m[ch]==0 && extra>0)
            {
                m[ch]=1;
                extra--;
                t++;
            }
        }
        
        // check if all the conditions satisfied
        for(char cc='a';cc<='z';cc++)
        {
            if(m[cc]==0)
            {
                return false;
            }
        }
        if(t<=k)
        {
            return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
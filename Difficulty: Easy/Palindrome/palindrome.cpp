class Solution {
  public:
    bool isPalindrome(int n) {
        // code here.
        int m=n;
        int rev =0;
        while(n>0)
        {
            int ld=n%10;
            rev=10*rev+ld;
            n=n/10;
            
        }
        if(m==rev) return true;
        else return false;
    }
};
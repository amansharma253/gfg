class Solution {
  public:
    int countDigits(int n) {
        // code here
        int cnt =int(log10(n)+1);
        return cnt;
    }
};
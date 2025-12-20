class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
         return (upper_bound(arr.begin(), arr.end(), k-1) - arr.begin());
    }
};
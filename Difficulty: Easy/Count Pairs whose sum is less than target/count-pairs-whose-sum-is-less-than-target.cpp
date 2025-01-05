//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int left = 0, right = n - 1;
        int count = 0;
        
        while (left < right) {
            if (arr[left] + arr[right] < target) {
                // All pairs (arr[left], arr[left+1]), ..., (arr[left], arr[right]) are valid
                count += (right - left);
                left++;
            } else {
                right--; // Decrease the sum by reducing the larger number
            }
        }
        return count;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
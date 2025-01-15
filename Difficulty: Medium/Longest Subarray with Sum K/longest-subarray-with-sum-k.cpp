//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp; // To store prefix sums
        int ans = 0;               // Stores the maximum subarray length
        int sum = 0;               // Tracks the cumulative sum
        
        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            sum += arr[i]; // Update the cumulative sum
            
            // Case 1: If the entire subarray from the start has sum equal to k
            if (sum == k) {
                ans = max(ans, i + 1);
            }

            // Case 2: Check if there's a prefix sum that allows a subarray with sum k
            if (mp.find(sum - k) != mp.end()) {
                ans = max(ans, i - mp[sum - k]);
            }

            // Store the first occurrence of the current cumulative sum
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return ans; // Return the maximum length found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  class Meet {
      public:
        int start;
        int end;
        int pos;
    };
    
 
    void merge(Meet arr[], int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        Meet L[n1], R[n2];
        for (int i = 0; i < n1; i++) {
            L[i].start = arr[l + i].start;
            L[i].end = arr[l + i].end;
            L[i].pos = arr[l + i].pos;
        }
        for (int j = 0; j < n2; j++) {
            R[j].start = arr[mid + 1 + j].start;
            R[j].end = arr[mid + 1 + j].end;
            R[j].pos = arr[mid + 1 + j].pos;
        }
        int i = 0;
        int j = 0; 
        int k = l;

        while (i < n1 && j < n2) {
            if (L[i].end <= R[j].end) {
                arr[k].start = L[i].start;
                arr[k].end = L[i].end;
                arr[k].pos = L[i].pos;
                i++;
            } else {
                arr[k].start = R[j].start;
                arr[k].end = R[j].end;
                arr[k].pos = R[j].pos;
                j++;
            }
            k++;
        }


        while (i < n1) {
            arr[k].start = L[i].start;
            arr[k].end = L[i].end;
            arr[k].pos = L[i].pos;
            i++;
            k++;
        }

      
        while (j < n2) {
            arr[k].start = R[j].start;
            arr[k].end = R[j].end;
            arr[k].pos = R[j].pos;
            j++;
            k++;
        }
    }

    void mergeSort(Meet arr[], int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;

          
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);

            merge(arr, l, mid, r);
        }
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
         Meet arr[n];
        for (int i = 0; i < n; i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }

        mergeSort(arr, 0, n - 1);

        int count = 1;
        int freeTime = arr[0].end;

   
        for (int i = 1; i < n; i++) {
            if (arr[i].start > freeTime) {
                count++;
                freeTime = arr[i].end;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
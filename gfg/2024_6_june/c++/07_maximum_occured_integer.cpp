// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(maxx + 2)

// CODE

class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        vector<int> arr(maxx + 2, 0);
        for(int i = 0; i < n; i++){ // initial occurence in vector of each no.
            arr[l[i]]++;
            arr[r[i] + 1]--;
        }
        
        int sum = 0;
        for(int i = 0; i <= maxx; i++){ // vector with occurence of every no, in each range
            arr[i] += sum;
            sum = arr[i];
        }
        
        int ans = 0;
        for(int i = 1; i < maxx; i++){ // calcualting maximum freq number which is at index i
            if(arr[i] > arr[ans]){
                ans = i;
            }
        }
        return ans;
    }
};
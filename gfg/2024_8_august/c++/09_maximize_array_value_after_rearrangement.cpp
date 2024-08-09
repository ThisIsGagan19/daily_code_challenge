// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    long long int mod = 1e9 + 7;
    int Maximize(vector<int> arr) {
        sort(arr.begin(), arr.end());
        long long int sum = 0;
        for(long i = 0; i < arr.size(); i++){
            sum = ((sum) + (long long int)(arr[i] * i)) % mod;
        }
        return sum % mod;
    }
};
// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    long long max_sum(int a[], int n) {
        
        long long sum = 0;
        for(long long i = 0; i < n; i++) sum += a[i];
        
        long long max = 0;
        long long initial = 0;
        for(long long i = 0; i < n; i++) initial += i*a[i];
        max = initial;
        for(long long i = 1; i < n; i++){
            long long next = initial - (sum - a[i-1]) + 1LL * (n-1)*a[i-1];
            initial = next;
            if(max < initial){
                max = initial;
            }
        }
        return max;
    }
};
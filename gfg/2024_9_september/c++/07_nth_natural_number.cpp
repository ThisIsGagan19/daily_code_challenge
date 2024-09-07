// TIME COMPEXITY
// O(logn)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    long long findNth(long long n) {
        // concept of base 9 number system.
        long long ans = 0;
        long long place = 1;
        while(n > 0){
            ans += place * (n % 9);
            n = n / 9;
            place = place * 10;
        }
        
        return ans;
    }
};
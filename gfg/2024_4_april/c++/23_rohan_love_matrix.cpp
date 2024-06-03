// INTUITION
// The trick here is to either use matrix exponentiation or just to figure out 
// that at position a[1][0], values will always follow the fibonacci order.

// CODE

class Solution {
    public:
    int firstElement(int n) {
        if(n == 1 or n == 2) return 1;
        int f = 1, s = 1, res = 0;
        for(int i = 0; i < n - 2; i++) {
            res = (f + s) % 1000000007;
            f = s;
            s = res;
        }
        return res;
    }
};
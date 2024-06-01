// NOTE: Check out how to convert gray code to binary code on youtube
// or any blog, after then it will be a easy problem.

// CODE

class Solution {
    public:
    int grayToBinary(int n) {
        int res = 0;
        while(n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
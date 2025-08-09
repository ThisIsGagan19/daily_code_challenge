// TC : O(1) - O(logN)
// SC : O(1) - O(1)

// CODE

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A1 -> using bit magic
        if(n <= 0) return false;
        return (n & (n-1)) == 0;

        // A2 -> using builtin functions
        if(n <= 0) return false;
        int cnt = __builtin_popcount(n);
        return cnt == 1;
        
        // A3 -> using recursion
        if(n <= 0) return false;
        if(n == 1) return true;
        return (n%2 == 0) && isPowerOfTwo(n/2);

        // A4 -> not interview based 
        if(n <= 0) return false;
        bool result = (static_cast<long long>(pow(2, 30)) % n) == 0;
        return result;

    }
};
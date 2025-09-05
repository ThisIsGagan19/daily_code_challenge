// TC = O(log(n))
// SC = O(1)

// CODE

class Solution {
public:
    int makeTheIntegerZero(int n1, int n2) {
        int t = 1;
        // t is from 1 to 36
        while(true){
            long long val = (long long)n1 - ((long long)t * n2);
            if(val < 0) return -1;
            if(__builtin_popcountll(val) <= t && t <= val){ // O(logn)
                return t;
            }
            t++;
        }
        return -1;
    }
};
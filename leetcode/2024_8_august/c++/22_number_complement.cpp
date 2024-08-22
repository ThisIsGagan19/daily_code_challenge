// TIME COMPEXITY
// O(logn)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    int findComplement(long num) {
        for(long i = 1; i <= num; i = i * 2){
            num = num ^ i;
        }
        return num;
    }
};
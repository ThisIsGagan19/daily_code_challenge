// TC : O(1) - O(logN)
// SC : O(1) - O(logn)

// CODE

class Solution {
public:
    bool isPowerOfThree(int n) {
        // not interview based approach
        int flag = 0;
        int i = 0;
        while (i <=30 ) {
            if (n == pow(3,i)) {
                flag = 1;
                break;
            }
            i++;
        }
        if (flag == 1) {
            return true;
        } 
        else {
            return false;
        }

        // using recursion
        if(n <= 0) return false;
        if(n == 1) return true;

        return (n%3 == 0) && isPowerOfThree(n/3);

        // looking for the bit approach
        // not found yet

        // but a different appraoch is found
        // this number is max power of 3 in the constraints so if n divides this and grateer than 0 then return true
        return n > 0 && 1162261467 % n == 0;
    }
};
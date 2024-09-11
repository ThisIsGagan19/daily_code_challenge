// TIME COMPEXITY
// O(logn)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int ans = start ^ goal;
        while(ans){
            cnt += (ans & 1);
            ans = (ans >> 1);
        }
        return cnt;
    }
};
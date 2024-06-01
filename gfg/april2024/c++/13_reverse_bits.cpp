// CODE

class Solution {
    public:
    long long reversedBits(long long x) {
        long long res = 0;
        for(int i = 0; i < 32; i++)
            if((x >> i) & 1) res += pow(2, (31 - i));
        return res;
    }
};
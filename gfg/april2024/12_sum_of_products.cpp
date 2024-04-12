// CODE

class Solution {
    public:
    long long pairAndSum(int n, long long arr[]) {
        long long res = 0;
        for(int b = 0; b < 32; b++) {
            long long count = 0;
            for(int i = 0; i < n; i++) {
                if((arr[i] & (1L << b))) count++;
            }
            res += (count * (count - 1) / 2) * (1L << b);
        }
        return res;
    }
};
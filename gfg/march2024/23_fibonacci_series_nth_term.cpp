// CODE

class Solution {
    public:
    vector<int> Series(int n) {
        vector<int> res(n + 1, 0); res[1] = 1;
        for(int i = 2; i <= n; i++) res[i] = (res[i - 1] + res[i - 2]) % (int)(1e9 + 7);
        return res;
    }
};
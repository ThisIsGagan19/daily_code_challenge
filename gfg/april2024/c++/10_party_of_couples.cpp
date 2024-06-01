// CODE

class Solution {
    public:
    int findSingle(int n, int arr[]) {
        int xorboi = 0;
        for(int i = 0; i < n; i++)
            xorboi ^= arr[i];
        return xorboi;
    }
};
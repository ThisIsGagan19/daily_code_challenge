// CODE

class Solution {
public:
    long long minEnd(int n, int x) {
        if(n==1){
            return x;
        }
        if(x==0){
            return n-1;
        }

        long long ans = x;
        long long tmp = x;
        long long set = 1;
        n -= 1;
        for(int i = 0; i < 63 && n > 0; i++){
            if(((tmp >> i) & 1) == 0){
                if((n & 1) == 1){
                    ans |= (set << i);
                }
                n >>= 1;
            }
        }
        return ans;
    }
};
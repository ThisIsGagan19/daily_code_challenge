// CODE

class Solution {
    public:
        const int mod = 1e9 + 7;
        int binary_expoential_power(long long a, long long b){
            if(b == 0) return 1;
            long long half = binary_expoential_power(a,b/2);
            long long res = (half * half) % mod;
            if(b%2 == 1){
                res = (res * a) % mod;
            }
            return res;
        }
        int countGoodNumbers(long long n) {
            return (long long)binary_expoential_power(5,(n+1)/2) * binary_expoential_power(4,n/2) % mod;
        }
};
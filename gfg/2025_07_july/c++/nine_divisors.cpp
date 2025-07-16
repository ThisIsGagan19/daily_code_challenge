// APPROACH : by using seive method find all primes till sqrt(N) then two ways of finding numbers of 9 divisors first -> (p)^8 and second -> (p^2 * q^2) both will give numbers which have 9 divisors.

// TC : O(sqrt(N) * log(log(sqrt(N))) )
// SC : O(sqrt(N))

// CODE

class Solution {
  public:
    bool inPowRange(long long a, int n){
        long long val = 1;
        for(int i = 1; i <= 8; i++){
            val *= a;
            if(val > n){
                return false;
            }
        }
        return true;
    }
    int countNumbers(int n) {
        int k = sqrt(n);
        int cnt = 0;
        // seive for prime numbers array
        vector<bool>seive(k+1,true);
        seive[0] = seive[1] = false;
        for(int i = 2; i <= k; i++){
            if(seive[i] == true){
                for(int j = 2*i; j <= k; j += i){
                    seive[j] = false;
                }
            }
        }
        
        vector<long long>primes;
        for(long long i = 2; i <= k; i++){
            if(seive[i] == true){
                primes.push_back(i);
            }
        }
        
        // p^8 wale cases
        for(int i = 0; i < primes.size(); i++){
            long long a = primes[i];
            if(inPowRange(a,n)){
                cnt++;
            }
            else{
                break;
            }
        }
        
        // p^2 * q^2 wale cases
        for(int i = 0; i < primes.size(); i++){
            for(int j = i+1; j < primes.size(); j++){
                long long a = primes[i];
                long long b = primes[j];
                long long val = a*a * 1LL * b*b;
                if(val > n){
                    break;
                }
                cnt++;
            }
        }
        
        return cnt;
    }
};
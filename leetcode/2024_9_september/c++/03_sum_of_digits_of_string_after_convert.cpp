// CODE

class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        
        int ans=0;
        int n=s.length();
        k--;
        for(int i=0;i<n;i++){
            int integral= s[i]-'a'+1;
            ans+=sumOfDigits(integral);
        }
        while(k){
           ans= sumOfDigits(ans);
           k--;
        }
        return ans;
    }
};
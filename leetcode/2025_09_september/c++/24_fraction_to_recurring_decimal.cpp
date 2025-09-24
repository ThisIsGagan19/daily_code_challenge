// TC = O(deno)
// SC = O(deno)

// CODE

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if(numerator == 0) return "0";
        if((long long)numerator * (long long)denominator < 0) res += '-';

        long long num = labs(numerator);
        long long deno = labs(denominator);

        long long div = num / deno;
        res += to_string(div);

        long long rem = num % deno;
        if(rem == 0){
            return res;
        }

        res += '.';

        unordered_map<long long, int> mp;
        while(rem != 0){
            if(mp.count(rem)){
                res.insert(mp[rem], "(");
                res += ')';
                break;
            }
            mp[rem] = res.length();
            
            rem = rem * 10;
            int rem2 = rem / deno;
            res += to_string(rem2);
            rem = rem % deno;
        }
        return res;
    }
};
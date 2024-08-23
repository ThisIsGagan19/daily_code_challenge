// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    string fractionAddition(string exp) {
        int numen = 0;
        int deno = 1;
        int i = 0;
        int n = exp.length();

        while(i < n){
            int abhiNumen = 0;
            int abhiDeno = 0;
            bool neg = (exp[i] == '-');
            if(exp[i] == '-' || exp[i] == '+'){
                i++;
            }
            // numen
            while(i < n && isdigit(exp[i])){
                    abhiNumen = (abhiNumen*10) + exp[i]-'0';
                    i++;
            }
            i++;
            // deno
            while(i < n && isdigit(exp[i])){
                    abhiDeno = (abhiDeno*10) + exp[i]-'0';
                    i++;
            }
            if(neg == true){
                abhiNumen = abhiNumen * (-1);
            }

            numen = abhiNumen * deno + numen * abhiDeno;
            deno = deno * abhiDeno;
        }

        int gcd = abs(__gcd(numen,deno));
        numen = numen / gcd;
        deno = deno / gcd;

        string ans = to_string(numen) + '/' + to_string(deno);

        return ans;
        
    }
};
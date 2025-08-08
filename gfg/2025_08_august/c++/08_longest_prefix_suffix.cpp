// TC : O(N^2)
// SC : O(1)

// CODE

class Solution {
  public:
    int getLPSLength(string &str) {
        int p = 0;
        int s = 1;
        int posi = 1;
        int cnt = 0;
        int n = str.length();
        while(p < n && s < n){
            if(str[p] == str[s]){ // case of matching increse both p & s
                p++;
                s++;
                cnt++;
            }
            else if(str[p] != str[s]){ // case of not matching p ko start pe le jao
                p = 0; // prefix ko start pe le jao
                posi++;
                cnt = 0; // reset the count
                s = posi; // prevent the extra iternation that will in future leads to N^2 complexity
            }
        }
        return cnt;
    }
};


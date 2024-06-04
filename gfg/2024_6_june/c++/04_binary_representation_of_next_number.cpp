// APPROACH
// simple digital logic of addition
// right se aate jao jab thk phela 0 na mile 
// jese he 0 mile usko 1 krke uske aage ke zero kr do and return kr do

// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    string binaryNextNumber(string s) {
        int i = 0, n = s.size();
        string res = "";
        
        // handling leading zeros
        while(i < n) {
            if(s[i] == '1') break;
            i++;
        }
        if(i == n) return "1"; // all zero simply return one 
        else res = s.substr(i); // remove leading zeros
        
        // main logic
        n = res.size();
        for(int i = n - 1; i >= 0; i--) {
            if(res[i] == '0') {
                res[i] = '1';
                for(int j = i + 1; j < n; j++)
                    res[j] = '0';
                return res;
            }
        }
        
        // handling all set bits. when all bitsare one
        for(int i = 0; i < n; i++)
            res[i] = '0'; // sare ones ko zeros bna do
        res = "1" + res;  // aage one laga ke return krva do
        
        return res;
    }
};
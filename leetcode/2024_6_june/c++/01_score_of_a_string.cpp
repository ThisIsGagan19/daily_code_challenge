class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i = 1; i < s.length(); i++){ // traversing the string
            sum += abs(s[i] - s[i-1]);  // adding up the abs value to sum and return sum
        }
        return sum;
    }
};
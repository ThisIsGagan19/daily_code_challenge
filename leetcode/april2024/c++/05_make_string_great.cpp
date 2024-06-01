// CODE

class Solution {
    public:
    string makeGood(string s) {
        int end = 0;
        for(int i = 0; i < s.size(); i++) {
            if(end > 0 && abs(s[i] - s[end - 1]) == 32) {
                end -= 1;
            } else {
                s[end] = s[i];
                end += 1;
            }
        }
        return s.substr(0, end);
    }
};
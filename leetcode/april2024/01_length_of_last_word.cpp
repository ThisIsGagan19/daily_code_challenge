// CODE

class Solution {
    public:
    int lengthOfLastWord(string s) {
        int cnt = 0, end = s.size() - 1;
        while (end >= 0 and s[end] == ' ') end--;
        while (end >= 0 and s[end] != ' ') cnt++, end--;
        return cnt;
    }
};
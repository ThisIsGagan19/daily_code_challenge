// CODE

class Solution {
    public:
    string removeKdigits(string num, int k) {
        string res;
        for(char c: num) {
            // keeping only n - k smaller elements in stack i.e., res string
            while((res.size()) and (c < res.back()) and k) res.pop_back(), k--;
            if(res.size() + (c - '0')) res.push_back(c);
        }
        while(k-- and res.size()) res.pop_back();
        return res.size() ? res : "0";
    }
};
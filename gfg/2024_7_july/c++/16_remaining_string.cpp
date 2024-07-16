// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:

    string printString(string s, char ch, int count) {
        int len = s.length();
        string res;
        char c;
        for(int i = 0; i < len; i++){
            char c = s[i];
            if(count <= 0){
                res += c;
            }
            if(c == ch && count > 0) 
                count--;
        }
        return res;
    }
};
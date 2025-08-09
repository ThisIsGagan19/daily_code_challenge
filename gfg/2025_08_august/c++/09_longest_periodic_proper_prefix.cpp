// TC : O(N^2)
// SC : O(N)

// CODE

class Solution {
  public:
    int getLongestPrefix(string &s) {
        int prefix = 0;
        int suffix = 1;
        int count = 0;
        int pos = 1;

        while (prefix < (int)s.length() && suffix < (int)s.length()) {
            if (s[prefix] == s[suffix]) {
                prefix++;
                suffix++;
                count++;
            } else {
                prefix = 0;
                pos++;
                suffix = pos;
                count = 0;
            }
        }

        if (count > 0) {
            int length = s.length() - 1;
            while (true) {
                string sub = s.substr(0, length);
                string str = sub + sub;
                if (str.rfind(s, 0) == 0) { // startsWith equivalent in C++
                    return length;
                }
                length--;
                if (length <= 0) break; // to avoid infinite loop
            }
        }
        return -1;
        
    }
};
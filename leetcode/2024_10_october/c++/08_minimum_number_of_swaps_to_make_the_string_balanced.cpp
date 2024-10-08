// CODE

class Solution {
public:
    int minSwaps(string s) {
        int i = 0, j = s.length() - 1;
        int closing = 0, opening = 0;
        int count = 0;
        while (i < j) {
            if (s[j] == ']') j--;
            if (s[i] == '[') opening++;
            else closing++;
            if (closing > opening) {
                j--;
                closing--;
                opening++;
                count++;
            }
            i++;
        }
        return count;
    }
};
class Solution {
public:

    // Two pointer approach.

    // TC = O(N)
    // SC = O(1)

    int appendCharacters(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        int i = 0; // pointer to s string
        int j = 0; // pointer to t string

        while(i < s_len && j < t_len){
            if(s[i] == t[j]){ // found means search next char from string t in string s so both i++ and j++
                i++;
                j++;
            }
            else{   // not eaual means search in next index so i++
                i++;
            }
        }

        return t_len - j; // return thelength of string which is not found so have to append in the end of string s
    }
};
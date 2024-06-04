// INTUITION
// we have to store the frequency of char and count how many are even and odd.

// APPROACH
// 01 make map of char and int to store frequency.
// 02 make var ans of int type.
// 03 traverse in string and store the freq if freq is even increase ans by 2.
// 04 traverse in map if a single freq is odd increament ans by 1 and break from loop.
// 05 return your ans.

// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(26 + 26)

// CODE

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> cnt;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            cnt[s[i]]++;
            if(cnt[s[i]] % 2 == 0) ans += 2;
        }

        for(auto it : cnt){
            if(it.second % 2 != 0){
                ans += 1;
                break;
            }
        }
        return ans;
    }
};
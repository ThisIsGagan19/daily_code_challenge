// INTUITION
// we have to store the frequency of char and count how many are even and odd.

// APPROACH
// 1. make map of char and int to store frequency.
// 2. make var ans of int type.
// 3. traverse in string and store the freq if freq is even increase ans by 2.
// 4. traverse in map if a single freq is odd increament ans by 1 and break from loop.
// 5. return your ans.

// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(26 + 26)

// CODE

class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = {}
        for ch in s:
            freq[ch] = freq.get(ch, 0) + 1
        
        res = 0
        has_odd = False
        for count in freq.values():
            if(count % 2) == 0:
                res += count
            else:
                res += count - 1
                has_odd = True
        
        return res + 1 if has_odd else res
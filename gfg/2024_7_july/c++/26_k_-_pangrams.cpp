// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:

    bool kPangram(string str, int k) {
        unordered_map<char,int> freq;
        int len_without_spaces = 0;
        for(auto ch : str){
            if(ch != ' '){
                freq[ch]++;
                len_without_spaces++;
            }
        }
        if(len_without_spaces < 26) return false;
        if(freq.size() == 26) return true;
        
        if(26 - freq.size() <= k) return true;
        return false;
    }
};
class Solution {
  public:
    string oddEven(string s) {
        unordered_map<char, int> freq;
        int x = 0; // storing even
        int y = 0;// storing odd
        
        // storing frequency of alphabet in map
        for(char ch : s){
            freq[ch]++;
        }
        
        // storing index of alphabet
        for(auto &it : freq){
            char ch = it.first; // storing char
            int cnt = it.second; // storing frequency of that char
            
            int ind = ch -'a' + 1; // 1 based indexing as 0 is neither odd nor even
            
            // check condition for even and x++
            if(cnt % 2 == 0 && ind % 2 == 0) x++; // both condition cnt and ind should be even
            // check condition for odd and y++
            if(cnt % 2 == 1 && ind % 2 == 1) y++; // both condition cnt and ind should be odd
        }
        // calculating total of x and y
        int total = x + y;
        // check condition of even and odd final condition
        if(total % 2 == 0){
            return "EVEN";
        }
        return "ODD";
    }
};
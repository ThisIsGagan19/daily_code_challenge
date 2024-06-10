// TIME COMPLEXITY
// O(nlogn)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        vector<char> matchingOrder = {'!', '#', '$', '%', '&', '*' ,'?', '@', '^'};
        unordered_set<char> nutSet(nuts, nuts + n);
        int idx = 0;
        char *res = new char[n];
        for(int i = 0; i < 9; i++) {
            char ch = matchingOrder[i];
            if(nutSet.find(ch) != nutSet.end()) {
                res[idx] = ch;
                idx++;
            }
        }
        
        for(int i = 0; i < idx; i++) {
            nuts[i] = res[i];
            bolts[i] = res[i];
        }

        delete[] res;
    }
};
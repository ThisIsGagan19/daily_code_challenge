// TIME COMPLEXITY
// O(nlogn)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    int countNumberswith4(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            string s = to_string(i);
            for(char ch : s) {
                if(ch == '4') {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
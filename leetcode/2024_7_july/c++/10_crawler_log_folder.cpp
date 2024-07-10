// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../") {
                if(cnt > 0) cnt--;
                else cnt = 0;
            }
            else if(logs[i] == "./") continue;
            else cnt++;
                
        }
        return cnt;
    }
};
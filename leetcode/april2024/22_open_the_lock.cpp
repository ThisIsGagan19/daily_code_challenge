// CODE

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        queue<string> q;
        
        q.push("0000");
        vis.insert("0000");

        if(dead.find("0000") != dead.end()) return -1;

        int res = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string curr = q.front(); q.pop();

                if(curr == target) return res;
                if(dead.find(curr) != dead.end()) continue;

                for(int i = 0; i < 4; i++) {
                    char old = curr[i];
                    
                    // clockwise rotation
                    curr[i] = (old == '9' ? '0' : old + 1);
                    if(dead.find(curr) == dead.end() and vis.find(curr) == vis.end()) {
                        q.push(curr);
                        vis.insert(curr);
                    }

                    // anti-clockwise rotation
                    curr[i] = (old == '0' ? '9' : old - 1);
                    if(dead.find(curr) == dead.end() and vis.find(curr) == vis.end()) {
                        q.push(curr);
                        vis.insert(curr);
                    }

                    curr[i] = old;
                }
            }
            res++;
        }

        return -1;
    }
};
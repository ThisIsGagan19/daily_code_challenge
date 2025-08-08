// TC : O(N)
// SC : O(N)

// CODE

class Solution {
  public:
    int minDifference(vector<string> &arr) {
        vector<int> sec;
        for(auto it : arr){
            int h = stoi(it.substr(0,2));
            int m = stoi(it.substr(3,2));
            int s = stoi(it.substr(6,2));
            int total_sec = h*60*60 + m*60 + s;
            sec.push_back(total_sec);
        }
        
        sort(sec.begin(), sec.end());
        
        int diff = INT_MAX;
        for(int i = 1; i < sec.size(); i++){
            diff = min(diff, sec[i] - sec[i-1]);
        }
        
        int rotation = 24*60*60;
        diff = min(diff, sec[0] + rotation - sec[sec.size() - 1]);
        
        return diff;
        
    }
};
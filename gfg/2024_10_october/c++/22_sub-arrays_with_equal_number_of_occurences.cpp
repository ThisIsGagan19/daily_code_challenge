// CODE

class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt_x = 0;
        int cnt_y = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == x) cnt_x++;
            if(arr[i] == y) cnt_y++;
            
            if(mp.find(cnt_x - cnt_y) != mp.end()){
                ans += mp[cnt_x - cnt_y];
            }
            mp[cnt_x - cnt_y]++;
        }
        return ans;
    }
};
// CODE

class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            ans ^= arr[i];
        }
        if(ans != 0) return 0;
        return pow(2,arr.size() - 1) - 1;
    }
};
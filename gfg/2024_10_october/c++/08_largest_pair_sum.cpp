// CODE

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int larg = 0, sec = 0;
        for(auto it: arr){
            larg = max(larg, it);
        }
        for(auto it: arr){
            if(it!=larg){
                sec = max(sec, it);
            }
        }
        return larg+sec;
    }
};
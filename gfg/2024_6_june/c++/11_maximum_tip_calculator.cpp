// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int,pair<int,int>>> diffArr;
        
        for(int i = 0; i < arr.size(); i++){
            diffArr.push_back({abs(arr[i] - brr[i]), {arr[i], brr[i]}});
        }
        
        sort(diffArr.rbegin(), diffArr.rend());
        
        long long ans = 0;
        
        for(int i = 0; i < diffArr.size(); i++){
            if(x == 0){
                ans += diffArr[i].second.second;
            }
            else if(y == 0){
                ans += diffArr[i].second.first;
            }
            else{
                if(diffArr[i].second.first > diffArr[i].second.second){
                    x--;
                    ans += diffArr[i].second.first;
                }
                else{
                    y--;
                    ans += diffArr[i].second.second;
                }
            }
        }
        
        return ans;
        
    }
};
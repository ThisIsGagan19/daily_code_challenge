// CODE

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        sort(arr.begin(),arr.end());
        for(int i=2;i<arr.size();i++){
            
            unordered_map<int,int>mp;
            for(int j=0;j<i;j++){
                if(mp.find(arr[i]-arr[j])!=mp.end()){
                    return true;
                }
                mp[arr[j]]++;
            }
        }
        return false;
    }
};
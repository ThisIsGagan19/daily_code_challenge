// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        map<int,int> mp;
        vector<pair<int,int> > store;  // num, freq
        vector<int> ans;
        
        for(auto it : arr)  mp[it]++;
        for(auto it : mp){
            store.push_back({it.first, it.second});
        }
        
        sort(store.begin(), store.end(), cmp);
        
        for(auto it : store){
            int num = it.first;
            int freq = it.second;
            while(freq--){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
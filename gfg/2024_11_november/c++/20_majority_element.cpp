// CODE

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        map<int,int>m;
        vector<int>v;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto i:m){
            if(i.second>arr.size()/3){
                v.push_back(i.first);
            }
        }
        return v;
    }
};
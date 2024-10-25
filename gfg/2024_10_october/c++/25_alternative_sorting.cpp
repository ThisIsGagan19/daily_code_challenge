class Solution {
  public:
    vector<int> alternateSort(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int n=arr.size();
        int st=0,end=n-1;
        int mid = st+(end-st)/2;
        while(st<end){
            ans.push_back(arr[end]);
            ans.push_back(arr[st]);
            st++;
            end--;
        }
        if(n%2==1){
            ans.push_back(arr[mid]);
        }
        return ans;
    }
};
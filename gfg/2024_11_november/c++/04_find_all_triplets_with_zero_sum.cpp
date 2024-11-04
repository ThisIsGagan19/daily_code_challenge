// CODE

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr){
        int n = arr.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int sum = -(arr[i] + arr[j]);
                if (mp.find(sum) != mp.end())
                {
                    for (int k : mp[sum])
                    {
                        if (k > j)
                        {
                            ans.push_back({i, j, k});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
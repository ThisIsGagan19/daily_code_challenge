class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> ranked(n);
        for (int i = 0; i < n; i++)
            ranked[i] = {arr[i], i};
        sort(ranked.begin(), ranked.end());
        int currRank = 0, prev = INT_MIN;
        vector<int> result(n);
        for (auto& p : ranked) {
            if (p.first > prev) {
                currRank++;
                prev = p.first;
            }
            result[p.second] = currRank;
        }
        return result;
    }
};
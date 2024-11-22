// CODE

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> hash;
        for (int i = 0; i < matrix.size(); i++) {
            string s;
            for (int j = 0; j < matrix[0].size(); j++) {
                s += to_string(matrix[i][j]);
            }
            hash[s]++;
        }

        int ans = 0;
        for (auto i : hash) {
            string s2 = find_inv(i.first);
            int secval = hash.count(s2) ? hash[s2] : 0;
            ans = max(ans, i.second + secval);
        }

        return ans;
    }

    string find_inv(const string& s) {
        string s2;
        for (char c : s) {
            s2 += (c == '0' ? '1' : '0');
        }
        return s2;
    }
};
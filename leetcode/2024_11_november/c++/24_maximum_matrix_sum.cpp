// CODE

class Solution {
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll  ans = 0;
        int total_neg = 0;
        int smallest = 1e5 + 1;
        for(auto &vec : matrix){
            for(auto &ele : vec){
                if( ele < 0)total_neg++;
                smallest = min(abs(ele), smallest);
                ans += abs(ele);

            }
        }
        // cout << total_neg << " " << smallest <<endl;
        return (total_neg & 1) ? ans - (2 *smallest) : ans;
    }
};
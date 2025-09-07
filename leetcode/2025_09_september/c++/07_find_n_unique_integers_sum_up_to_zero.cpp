// TC = O(N) OR O(N/2)
// SC = O(1)

// CODE

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        // int sum = ((n-1)*n) / 2;
        // ans.push_back(-sum);
        // for(int i = 1; i < n; i++){
        //     ans.push_back(i);
        // }
        // return ans;


        // approach 2
        if(n%2 != 0) ans.push_back(0);

        for(int i = 1; i <= n/2; i++){
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};
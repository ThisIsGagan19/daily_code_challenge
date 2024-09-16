// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> min_arr(n);
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            string time = timePoints[i];

            string HH_str = time.substr(0,2);
            string MM_str = time.substr(3);

            // int me badal
            int HH_int = stoi(HH_str);
            int MM_int = stoi(MM_str);

            min_arr[i] = (HH_int * 60) + MM_int;
        }

        sort(min_arr.begin(), min_arr.end());
        for(int i = 1; i < n; i++){
            ans = min(ans, min_arr[i] - min_arr[i-1]);
        }

        return min(ans, (24 * 60 - min_arr[n-1]) + min_arr[0]);

    }
};
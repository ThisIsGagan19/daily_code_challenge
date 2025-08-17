// TC : O(N)
// SC : O(N)

// CODE

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> p(n+1,0.0);
        p[0] = 1;
        double currProbSum = (k == 0) ? 0 : 1;

        for(int i = 1; i <= n; i++){
            p[i] = currProbSum/maxPts;
            if(i < k){
                currProbSum += p[i];
            }
            if(i-maxPts >= 0 && i-maxPts < k){
                currProbSum -= p[i-maxPts];
            }
        }

        return accumulate(begin(p) + k, end(p), 0.0);
    }
};
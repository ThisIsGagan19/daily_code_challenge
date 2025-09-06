// TC = O(N*log(R)) where R is max range in queries
// SC = O(1)

// CODE

class Solution {
public:
    long long solve(long l, long r){
        long totalSteps = 0;
        long low = 1;
        long stepCounter = 1;
        while(stepCounter > 0){
            if(low > r) break; // stoping condition
            long high = 4*low - 1;
            // low and high defined now find the range st and end
            long st = max(low,l);
            long end = min(high,r);

            // find elements in the range of st and end only of st <= end
            if(st <= end){
                totalSteps += (end-st+1) * stepCounter; // multiply by stepCounter as ech element take stepCounter steps to become zero
            }
            stepCounter++;
            low = high + 1;
        }
        return totalSteps;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long ans = 0;
        for(auto q : queries){
            long step = solve(q[0], q[1]);
            ans += (step + 1) / 2;  // as we can take 2 numbers at a time
        }
        return ans;
    }
};
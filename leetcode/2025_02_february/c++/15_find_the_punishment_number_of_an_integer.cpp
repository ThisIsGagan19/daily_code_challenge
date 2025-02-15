// TC : O(n * 2^log10(n^2))
// SC : O(log10(n^2))

// Good Question - yt video link for understanding better = https://www.youtube.com/watch?v=SmnRAvkkohA

// CODE

class Solution {
    public:
        bool solve(int sq, int currSum, int num){
            if(sq == 0) return currSum == num;
            return solve(sq/10,currSum + sq%10, num) || solve(sq/100,currSum + sq%100, num) || solve(sq/1000,currSum + sq%1000, num) || solve(sq/10000,currSum + sq%10000, num);
        }
        int punishmentNumber(int n) {
            int ans = 0;
            for(int i = 1; i <= n; i++){
                int sq = i * i;
                if(solve(sq,0,i)){
                    ans += sq; 
                }
            }
            return ans;
        }
    };
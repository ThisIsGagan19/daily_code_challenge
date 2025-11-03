// CODE

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int n = colors.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int maxTime = neededTime[i];
            int sumTime = neededTime[i];
            // Find group of consecutive same-colored balloons
            while (j < n && colors[j] == colors[i]) {
                sumTime += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
                j++;
            }
            // For a group, remove all except the one with max neededTime
            totalCost += (sumTime - maxTime);
            i = j;
        }
        return totalCost;
    }
};
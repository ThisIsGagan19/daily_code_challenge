// CODE

class Solution {
  public:
    int maximumProfit(vector<int> &price) {
        int profit = 0;
        int n = price.size();
        for (int i = 1; i < n; i++) {
            if (price[i] > price[i - 1])
                profit += price[i] - price[i - 1];
        }
        return profit;
    }
};
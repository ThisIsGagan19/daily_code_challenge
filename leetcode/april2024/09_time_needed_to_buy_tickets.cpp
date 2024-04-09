// CODE

class Solution {
    public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if (tickets[k] == 1) return k + 1;
        int n = tickets.size(), res = 0;
        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {
                if (tickets[i] != 0) {
                    tickets[i]--;
                    res++;
                }
                if (tickets[k] == 0) return res;
            }
        }
        return res;
    }
};
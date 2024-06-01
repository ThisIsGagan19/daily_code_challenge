// CODE

class Solution {
    public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size(), i = 0, j = 0;
        bool flag = false;
        vector<int> res(n, 0);
        sort(deck.begin(), deck.end());
        while(j < n) {
            if(res[i] == 0) {
                if(!flag) {
                    res[i] = deck[j];
                    j++;
                }
                flag = !flag;
            }
            i = (i + 1) % n;
        }
        return res;
    }
};
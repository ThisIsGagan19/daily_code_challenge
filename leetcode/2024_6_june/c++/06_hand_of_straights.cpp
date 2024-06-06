// TIME COMPLEXITY
// O(nlogn) + O(n * groupSize)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int,int> cnt;
        for(int i = 0; i < n; i++){
            cnt[hand[i]]++; // O(nlogn)
        }

        while(!cnt.empty()){ // O(n * groupSize)
            int curr = cnt.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(cnt[curr + i] == 0) return false;
                cnt[curr + i]--;
                if(cnt[curr + i] < 1){
                    cnt.erase(curr + i);
                }
            } 
        }
        return true;
    }
};
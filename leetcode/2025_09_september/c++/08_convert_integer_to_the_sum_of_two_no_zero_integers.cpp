// TC = O(logN) where N is the given integer
// SC = O(1)

// CODE

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int place = 1;
        while(n > 1){
            int take = 1;
            if(n%10 == 1){
                take = 2;
            }
            a = a - (take*place);
            b = b + (take*place);

            n = (n-take) / 10;
            place *= 10;
        }
        return {a,b};
    }
};
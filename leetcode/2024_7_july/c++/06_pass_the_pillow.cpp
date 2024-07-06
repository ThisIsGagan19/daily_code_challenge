// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1;
        int step = 1;
        while (i>0 && i<=n && time>0) {
            i += step;
            time--;
            if (i==n || i==1) step = -step;
        }
        return i;
    }
};

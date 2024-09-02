// CODE

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        long long sum = 0;
        for (int j = 0; j < chalk.size(); j++)
            sum += chalk[j];
        while(k >= sum)
            k -= sum;
        while(k >= chalk[i]) {
            k -= chalk[i];
            i++;
            if (i == chalk.size())
                i = 0;
        }
        return i;
    }
};
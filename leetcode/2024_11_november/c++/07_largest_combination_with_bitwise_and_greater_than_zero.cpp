// CODE

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int maxCount = 0;

        // Check each bit position from 0 to 30
        for (int bit = 0; bit < 31; ++bit) {
            int count = 0;

            // Count how many numbers have the `bit` position set
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }

            // Update maxCount if this count is greater
            maxCount = std::max(maxCount, count);
        }

        return maxCount;
    }
};
// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int currPosition = 1;
        int previousCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while (curr->next != NULL) {
            
            if ((curr->val < prev->val &&
                 curr->val < curr->next->val) ||
                (curr->val > prev->val &&
                 curr->val > curr->next->val)) {

                    if (previousCriticalIndex == 0) {
                        previousCriticalIndex = currPosition;
                        firstCriticalIndex = currPosition;
                    } else {
                        minDistance =
                            min(minDistance, currPosition - previousCriticalIndex);
                        previousCriticalIndex = currPosition;
                    }
            }

            currPosition++;
            prev = curr;
            curr = curr->next;
        }

        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = previousCriticalIndex - firstCriticalIndex;
        return {minDistance, maxDistance};
    }
};
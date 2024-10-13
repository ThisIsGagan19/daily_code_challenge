// CODE

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        int max = numeric_limits<int>::min();
        int rangeLeft = 0, rangeRight = numeric_limits<int>::max();
        
        // Initialize the min-heap with the first element from each list
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i][0];
            minHeap.push(Element(val, i, 0));
            max = std::max(max, val);
        }
        
        while (minHeap.size() == nums.size()) {
            Element curr = minHeap.top();
            minHeap.pop();
            
            // Update range if smaller
            if (max - curr.val < rangeRight - rangeLeft) {
                rangeLeft = curr.val;
                rangeRight = max;
            }
            
            // If there are more elements in the current list
            if (curr.idx + 1 < nums[curr.list].size()) {
                int nextVal = nums[curr.list][curr.idx + 1];
                minHeap.push(Element(nextVal, curr.list, curr.idx + 1));
                max = std::max(max, nextVal);
            }
        }
        
        return {rangeLeft, rangeRight};
    }

private:
    struct Element {
        int val;
        int list;
        int idx;

        Element(int v, int l, int i) : val(v), list(l), idx(i) {}
        
        // Overloading the comparison operator for the priority queue
        bool operator>(const Element& other) const {
            return val > other.val;
        }
    };
};
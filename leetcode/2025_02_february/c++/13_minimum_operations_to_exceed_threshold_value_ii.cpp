// TC : O(n * logn)
// SC : O(n)

// main takeaway is that you should use pq(begin(nums), end(nums)) rather than for loop because for loop use n * logn TC when pushing the element in the heap and pq(begin(nums), end(nums)) uses heapify which takes O(logn) only for pushing elements in the heap.

// CODE

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long> > pq(begin(nums), end(nums)); // use heapify so O(logn)
        // below use O(n * logn)
        // for(int it : nums){ // O(n)
        //     pq.push(it); // O(logn)
        // }
        int cnt = 0;
        while(pq.top() < k){
            long a = pq.top();
            pq.pop(); // O(logn)
            long b = pq.top();
            pq.pop(); // O(logn)
            long c = a * 2 + b;
            pq.push(c); // O(logn)
            cnt++;
        }
        return cnt;
    }
};
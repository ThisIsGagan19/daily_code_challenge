// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &i : nums){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) pq.pop();

        return pq.top();
    }
};

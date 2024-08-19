// TIME COMPEXITY
// O(nlogk)

// SPACE COMPEXITY
// O(k)

// CODE

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> maxHeap;
        for(int i = 0; i < arr.size(); i++){
            maxHeap.push(arr[i]);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
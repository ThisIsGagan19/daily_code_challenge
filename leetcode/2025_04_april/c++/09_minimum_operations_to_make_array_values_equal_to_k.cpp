// CODE

class Solution {
    public:
        // good question example observering bahot important h jitne unique element jo greater h k se utne he operations lagange 
        // observation ka kese pata lagega pen-copy uta ke likh ke solve krke
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int> st;
            for(auto it : nums){
                if(it < k) return -1;
                else if(it > k){
                    st.insert(it);
                }
            }
            return st.size();
        }
};
class Solution {
  public:
    // TC = O(N)
    // SC = O(1)
    // we simply go reverse in queries and then if 0 then push element into result by xoring it with x(initial = 0)
    // as xor with 0 give that element same. and if 1 then change the value of x by xorint  x with that queries[1] element
    // then at last out from loop add 0 xor with x into the result
    // then sort the result and return the result
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        vector<int> res;
        int x = 0; // take it as a xoring element
        
        // traverse array in reverse order
        for(int i = queries.size() - 1; i >= 0; i--){
            if(queries[i][0] == 0){
                res.push_back(x^queries[i][1]);  // push element  xoring it with x
            }
            else{
                x = x ^ queries[i][1]; // changing the value of xoring elements 
            }
        }
        // push that initial 0 elements xoring with x
        res.push_back(0^x);
        sort(res.begin(), res.end());
        return res;
    }
};
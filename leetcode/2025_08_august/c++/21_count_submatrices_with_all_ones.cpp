// TC : O(N*M*N)
// SC : O(M)

// optimal approach = use monotonic stack

class Solution {
public:
    int oneDArraySolve(vector<int>& oneD){
        int consecutiveOnes = 0;
        int subArrCnt = 0;
        for(int i = 0; i < oneD.size(); i++){
            if(oneD[i] == 0){
                consecutiveOnes = 0;
            }
            else{
                consecutiveOnes++;
            }
            subArrCnt += consecutiveOnes;
        }
        return subArrCnt;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;

        for(int sr = 0; sr < n; sr++){
            vector<int> oneD(m,1);
            for(int er = sr; er < n; er++){
                for(int col = 0; col < m; col++){
                    oneD[col] = oneD[col] & mat[er][col];
                }
                res += oneDArraySolve(oneD);
            }
        }
        return res;
    }
};
// INTUITION
// Use backtracking, fill ones and then zeros according to condition

// CODE 

class Solution {
    public:	
    void solve(int i, int countOne, int countZero, string num, int &n, vector<string> &res) {
        if(i >= n) {
            res.push_back(num);
            return;
        }
        
        num += '1';
        solve(i + 1, countOne + 1, countZero, num, n, res);
        num.pop_back();
        
        if(countOne > countZero) {
            num += '0';
            solve(i + 1, countOne, countZero + 1, num, n, res);
        }
    }
    
	vector<string> NBitBinary(int n) {
	    vector<string> res;
	    string num = "";
	    solve(0, 0, 0, num, n, res);
	    return res;
	}
};
// TIME COMPLEXITY
// O(n*m)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        int row = -1;
        int maxcnt = 0;
        
        int n = arr.size();
        int m = arr[0].size();
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = m-1; j >= 0; j--){
                if(arr[i][j] == 0) break;
                cnt++;
            }
            if(cnt > maxcnt){
                maxcnt = cnt;
                row = i;
            }
        }
        return row;
    }
};
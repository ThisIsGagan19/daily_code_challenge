// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    int maxLength(string& str) {
        int maxi1 = 0, maxi2 = 0;
        int ob = 0, cb = 0;
        
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(') ob++;
            else cb++;
            if(cb > ob){
                cb = 0;
                ob = 0;
            }
            if(cb == ob) maxi1 = max(maxi1, ob*2);
        }
        
        ob = 0;
        cb = 0;
        for(int i = str.size() - 1; i >= 0; i--){
            if(str[i] == '(') ob++;
            else cb++;
            if(ob > cb){
                cb = 0;
                ob = 0;
            }
            if(cb == ob) maxi2 = max(maxi2, ob*2);
        }
        
        return max(maxi1, maxi2);
    }
};
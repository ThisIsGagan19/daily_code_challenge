// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution 
{
    public:
    bool knows(vector<vector<int> >& M, int n,int a,int b){
        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M) 
    {
        int n = M.size();
        stack<int> s;
        for(int i = 0; i < n; i++){
            s.push(i);
        }
        
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,n,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        // verfying step
        int candidate = s.top();
        
        bool rowCheck = false;
        int zeroCount = 0;
        for(int i = 0; i < n; i++){
            if(M[candidate][i] == 0){
                zeroCount++;
            }
        }
        if(zeroCount == n){
            rowCheck = true;
        }
        
        // col check
        bool colCheck = false;
        int oneCount = 0;
        for(int i = 0; i < n; i++){
            if(M[i][candidate] == 1){
                oneCount++;
            }
        }
        if(oneCount == n - 1){
            colCheck = true;
        }
        
        // final verfy
        if(rowCheck == true && colCheck == true){
            return candidate;
        }
        else{
            return -1;
        }
    }
};
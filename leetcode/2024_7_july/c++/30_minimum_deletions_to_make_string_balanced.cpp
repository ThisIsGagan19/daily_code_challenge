// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int c=0,ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a')c++;
           else if(s[i]=='b'&&c>0)c--,ans++;
        }
        return ans;
    }
};
// CODE

class Solution {
  public:
    int lps(string str) {
        int n=str.size();
        vector<int> v(n,0);
        
        int i=0,j=1;
        while(j<n){
            if(str[i]==str[j]){
                v[j]=i+1;
                i++;
                j++;
            }
            else if(i==0)
                j++;
            else
                i=v[i-1];
        }
        
        return v.back();
    }
};
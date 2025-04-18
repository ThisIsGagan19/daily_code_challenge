// COPIED
// CODE

class Solution {
    public:
        string rec(int n){
            if(n==1) return "1";
             string ans=rec(n-1);
             string ans2="";  
             int cnt=0;
             for( int i=0;i<ans.size();i++){
                  if(ans[i]==ans[i+1]) cnt++;
                   else {
                    ans2+=to_string(++cnt);
                     ans2+=ans[i];
                     cnt=0;
                   }
                }
             return ans2;
        }
        string countAndSay(int n) {
            string s="1";
         return rec(n);    
        }
    
};
// CODE

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int ind1=s1.size()-1;
        int ind2=s2.size()-1;
        int carry=0;
        string ans="";
        
        while(ind1 >= 0 && ind2 >= 0){
            int a = s1[ind1]-'0';
            int b = s2[ind2]-'0';
            
            int val = a^b^carry;
            if(carry == 0){
                if(a == 1 && b == 1){
                    carry=1;
                }
            }else{
                if(a == 0 && b == 0){
                    carry=0;
                }
            }
            
            ans=to_string(val)+ans;
            ind1--;
            ind2--;
        }
        
        while(ind1 >= 0){
            int a = s1[ind1]-'0';
            int val = a^carry;
            ans=to_string(val)+ans;
            if(carry == 1 && a == 1){
                carry=1;
            }else{
                carry=0;
            }
            ind1--;
        }
        
        while(ind2 >= 0){
            int a = s2[ind2]-'0';
            int val = a^carry;
            ans=to_string(val)+ans;
            if(carry == 1 && a == 1){
                carry=1;
            }else{
                carry=0;
            }
            ind2--;
        }
        if(carry){
            ans='1'+ans;
        }
        string newans="";
        int ind=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1'){
                ind=i;
                break;
            }
        }
       
        if(ind!=-1){
            for(int i=ind;i<ans.size();i++){
                newans+=ans[i];
            }
        }
        
        
        return newans;
        
    }
};
// CODE

class Solution {
public:
    vector<int>decrypt(vector<int>&code,int k) {
        vector<int>res(code.size());
        int len=code.size();
        if(k==0)
            return res;
        else if(k>0) {
            for(int i=0;i<len;i++) {
                int sum=0;
                for(int j=0;j<k;j++) {
                    sum+=code[(i+j+1)%len];
                }
                res[i]=sum;
            }
        } 
        else {
            k=abs(k);
            for(int i=0;i<len;i++) {
                int sum=0;
                for(int j=0;j<k;j++) {
                    sum+=code[(i-j-1+len)%len];
                }
                res[i]=sum;
            }
        }
        return res;
    }
};
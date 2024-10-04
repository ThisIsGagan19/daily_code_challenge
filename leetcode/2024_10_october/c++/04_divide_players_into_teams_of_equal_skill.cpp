class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long s=0;
        int n=skill.size();
        int k=n/2;
        

        map<long long,long long>mpp;
        map<int,int>frq;
      

        for(int i=0;i<n;i++){
            mpp[skill[i]]++;
            s+=skill[i];
        }
       
        if(s%k!=0) return -1;
        s=s/k;

        long long ans=0;


        for(int i=0;i<n;i++){
            long long req=s-skill[i];
            if(frq[skill[i]]>0) continue ;

            //check frq of both chars so that we can make pair of every chr
            if(mpp[req]==mpp[skill[i]]){

                // if both chars of pair are same like {3,3}
                if(req==skill[i]){
                    if(mpp[req]%2!=0) return -1;
                    ans+=(mpp[req]*(req*skill[i]))/2;
                }
                else ans+=mpp[req]*(req*skill[i]);
                // add to frq map so which tells us that current char is already mapped 
                frq[skill[i]]++;
                frq[req]++;
            }
            else return -1;
        }
      

        return ans;
    }
};

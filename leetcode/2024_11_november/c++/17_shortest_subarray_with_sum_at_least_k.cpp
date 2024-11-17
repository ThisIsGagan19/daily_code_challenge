// CODE

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        if(k==1){
            if(nums[0]>=k) return 1;

            return -1;
        }
        
        multiset<pair<long,long>>m1;
        long long  m=INT_MAX;
        long long sum=0;

        for(int i=0;i<size(nums);i++){
           sum+=nums[i];

           if(sum>=k) m=min(m,(long long )i+1);

           if( m1.size()>0 && sum-(m1.begin()->first) >=k){

            while(m1.size()>0 && sum-(m1.begin()->first) >=k){

              m=min(m,(long long)i-m1.begin()->second);
              m1.erase(m1.begin());

            }

           }
           m1.insert(make_pair(sum,i));
        }

        if(m==INT_MAX) return -1;

        return m;
    }
};
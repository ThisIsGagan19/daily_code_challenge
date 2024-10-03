// CODE

class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {

    // (a+b)%p = ((a%p)+(b%p))%p

    int totalProperty = 0;
    for(auto e:nums){
        totalProperty = ((totalProperty%p)+(e%p))%p;
    }

    if(totalProperty==0) return 0;

    unordered_map<int,int> propertyPreffix;
    propertyPreffix[0] = -1;
    // -1 0 1 2 

    int len = (int)nums.size();
    int currentProperty = 0;
    int answer = -1;
    for(int i=0;i<len;i++){
        auto e=nums[i];
        if(e%p==totalProperty) {
            answer = 1;
            break;
        }
        currentProperty = ((currentProperty%p)+(e%p))%p;

        int searchedPastProperty = ((currentProperty%p)-(totalProperty%p))%p;
        if(searchedPastProperty<0) searchedPastProperty += p;

        if(propertyPreffix.find(searchedPastProperty)!=propertyPreffix.end()){
            int j =  propertyPreffix[searchedPastProperty];
            int currentSubArrayLen = i - j;
            if(currentSubArrayLen!=len) {
                if(answer==-1) answer = currentSubArrayLen;
                else answer = min(answer,currentSubArrayLen);
            }
        }
        
        propertyPreffix[currentProperty] = i;
    }

    return answer;
}

};
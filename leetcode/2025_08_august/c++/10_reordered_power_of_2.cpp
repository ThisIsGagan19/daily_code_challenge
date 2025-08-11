// TC : O(1) as per the problem constraints 
// SC : O(1)

// CODE

class Solution {
public:
    int getCountNum(int n){
        int num = 0;
        while(n){
            num += pow(10,n%10);
            n /= 10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) {
        int num = getCountNum(n);
        for(int i = 0; i <= 29; i++){
            if(num == getCountNum(1<<i)){
                return true;
            }
        }
        return false;
    }
};
// CODE

class Solution {
private:
    bool isPrime(int n)
    {   
        if(n<=1) return false;
        for(int i = 2;i<=int(sqrt(n));i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        for(int i = nums.size()-2;i>=0;i--)
        {
            if(nums[i]>=nums[i+1])
            {
                int diff = nums[i] - nums[i+1];
                diff++;
                while(true)
                {
                    if(isPrime(diff) && (diff) < nums[i])
                    {
                        nums[i] -= diff;
                        break;
                    }
                    else if(diff >= nums[i])
                    {
                        return false;
                    }
                    else diff++;
                }
            }
        }
        return true;
    }
};
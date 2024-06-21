// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unsat = 0;

        // Calculate initial unsatisfied customers in the first 'minutes' window
        for (int i = 0; i < minutes; i++) {
            unsat += customers[i] * grumpy[i];
        }

        int maxUnsat = unsat;


        int i = 0;
        int j = minutes;

        while(j < n) {
            unsat += customers[j] * grumpy[j];        
            unsat -= customers[i] * grumpy[i];        
            
            maxUnsat = max(maxUnsat, unsat);               
            i++;
            j++;
        }

        int totalCustomers = maxUnsat;


        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }

        return totalCustomers;
    }
};
// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    int solve(int n, int k){
        if(n == 1) return 0;
        return (solve(n-1,k) + k ) % n;
    }
    int findTheWinner(int n, int k) {

        // method 2 recursive
        return solve(n,k) + 1;


        // method 1 using queue
        

        // queue<int> q;
        // for(int i = 1; i <= n; i++){
        //     q.push(i);
        // }

        // while(q.size() > 1){
        //     for(int i = 1; i < k; i++){
        //         q.push(q.front());
        //         q.pop();
        //     }
        //     q.pop(); // kth element removr kr diya
        // }

        // return q.front();
    }
};
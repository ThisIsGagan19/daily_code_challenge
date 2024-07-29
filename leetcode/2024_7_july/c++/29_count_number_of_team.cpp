// TIME COMPLEXITY
// O(n^2)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int numTeams(vector<int>& rating) {
         int n =rating.size();
        int team = 0;
        for(int j=1; j<n;j++){
            int countsmallerleft = 0;
            int countlargerleft = 0;
            int countlargerright =0;
            int countsmallerright = 0;
       
                for(int i= 0; i<j ;i++){
                    if(rating[i]<rating[j]){
                        countsmallerleft++;
                    }
                    else{
                        countlargerleft++;
                    }
                }

                for(int k=j+1; k<n ;k++){
                    if(rating[k]>rating[j]){
                        countlargerright++;
                     
                    }
                    else{
                         countsmallerright++;
                    }
                }
                  
                team += (countsmallerright * countlargerleft) + (countsmallerleft * countlargerright); 

        }
        return team;
    }
};
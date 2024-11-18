// CODE

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    int reverseArray(vector<int>&a,int s,int e){
        while(s<e){
            swap(a[s],a[e]);
            s++;
            e--;
        }
    }
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>&a, int d) {
        // code here
        int n=a.size();
        if (n == 0 || d == 0 || d == n) return;
        d=d%n;
            reverseArray(a,0,d-1);
            reverseArray(a,d,n-1);
            reverseArray(a,0,n-1);
       
    }
};
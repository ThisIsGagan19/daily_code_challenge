// TC : O(1)
// SC : O(n)

// CODE

class ProductOfNumbers {
    public:
        vector<int> arr;
        int n;
        ProductOfNumbers() {
            arr.clear();
            n = 0;
        }
        
        void add(int num) {
            if(num == 0){
                arr = {};
                n = 0;
            }
            else{
                if(arr.empty()){
                    arr.push_back(num);
                }
                else{
                    arr.push_back(arr[n-1] * num);
                }
                n++;
            }
        }
        
        int getProduct(int k) {
            if( k > n){
                return 0;
            }
            else if(k == n) {
                return arr[n-1];
            }
            else{
                return arr[n-1] / arr[n-k-1];
            }
        }
    };
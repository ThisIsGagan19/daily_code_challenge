// CODE

class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort( arr.begin(), arr.end(), greater<int>() );
        int n = arr.size(), sum=0;
        vector<char> v;
        for( int i=0; i<n; i+=2 ) {
            sum += arr[i];
            if( (i+1) < n )
                sum += arr[i+1];
            v.push_back( '0' + sum%10 );
            sum = sum/10;
        }
        if( sum )
            v.push_back( '0' + sum );
        while( v.back() == '0' )
            v.pop_back();
        return string( v.rbegin(), v.rend() );
    }
};
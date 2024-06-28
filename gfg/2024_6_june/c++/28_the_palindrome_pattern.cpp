// TIME COMPLEXITY
// O(m * n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int row=arr.size();
        int col=arr[0].size();
        bool check=false;
        for(int i=0;i<row;i++)
        {
            int k=0;int j=row-1;
             check=false;
            while(k<j)
            {
                if(arr[i][k]!=arr[i][j])
                {
                    check=true;
                    break;
                }
                k++;
                j--;
            }
            if(check==false)
            {
               string r=to_string(i);
               string ans=r+' '+'R';
               return ans;
            }
        }
        for(int i=0;i<col;i++)
        {
            int k=0;int j=row-1;
             check=false;
            while(k<j)
            {
                if(arr[k][i]!=arr[j][i])
                {
                    check=true;
                    break;
                }
                k++;
                j--;
            }
            if(check==false)
            {
               string r=to_string(i);
               string ans=r+' '+'C';
               return ans;
            }
        }
        return "-1";
    }
};
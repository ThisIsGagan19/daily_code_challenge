// CODE

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board)
     {
        string s = "";
        string target ="123450";
        int level=0;
        for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
         s+=(board[i][j]+'0');
          
          cout<<s<<endl;
         set<string> vis;
         vis.insert(s);
       
         queue<string>q;
         q.push(s);

         unordered_map<int,vector<int>> swapindex;
       swapindex[0]={1,3};
       swapindex[1]={0,2,4};
        swapindex[2]={1,5};
        swapindex[3]={0,4};
        swapindex[4]={3,5,1};
        swapindex[5]={4,2};

         while(!q.empty())
         {
            
            int n = q.size();
            while(n--)
            {
               string curr_str = q.front();
                if(curr_str==target)
                return level;
                q.pop();
               
                int index_of_zero = curr_str.find('0');
                for(auto it: swapindex[index_of_zero])
                {
                    string newstr = curr_str;
                    swap(newstr[index_of_zero],newstr[it]);
                    if(vis.find(newstr)==vis.end())
                    {
                       vis.insert(newstr);
                       q.push(newstr); 
                    }
                }

            }
            level++;
         }
        return -1;
     }
};
// CODE

#define ds pair<int,pair<int,int>>
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int ans=0;
        int dr[]={0,1,0,-1,0};
        if (grid[0][1]>1 && grid[1][0]>1)
            return -1;
        vector<vector<int>> vist(grid.size(), vector<int>(grid[0].size(),INT_MAX));
        priority_queue<ds,vector<ds>,greater<ds>> q;
        vist[0][0]=0;
        q.push({0,{0,0}});
        while (!q.empty()){
            int x=q.top().second.first, y=q.top().second.second, t=q.top().first+1;
            q.pop();
            // cout<<x<<' '<<y<<' '<<t<<endl;
            for (int i=0; i<4; i++){
                int nx=x+dr[i], ny=y+dr[i+1];
                if (nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()){
                    if (t<vist[nx][ny]){
                        if (t>=grid[nx][ny]){
                            vist[nx][ny]=t;
                            q.push({t,{nx,ny}});
                        }
                        else{
                            if ((grid[nx][ny]-t)%2){
                                vist[nx][ny]=grid[nx][ny]+1;
                                q.push({vist[nx][ny],{nx,ny}});
                            }
                            else{
                                vist[nx][ny]=grid[nx][ny];
                                q.push({vist[nx][ny],{nx,ny}});
                            }
                        }
                        if (vist.back().back()<INT_MAX)
                            return vist.back().back();
                    }
                }
            }
        }
        return -1;
    }
};
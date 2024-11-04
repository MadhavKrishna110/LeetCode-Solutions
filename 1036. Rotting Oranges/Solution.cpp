class Solution {
public:
   bool isValid(int x,int y,int m,int n){
    if(x<0||x>=m||y<0||y>=n) return false;
    return true;
   }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if( grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int days=0;
        while(!q.empty()){
            pair<int,int> p = q.front().second;
            int x=p.first;
            int y =p.second;
            int cnt=q.front().first;
            q.pop();
            days= max(days,cnt);


            if(isValid(x+1,y,m,n) && grid[x+1][y]==1){
                grid[x+1][y]=2;
                q.push({cnt+1,{x+1,y}});
            }
            if(isValid(x-1,y,m,n) && grid[x-1][y]==1){
                grid[x-1][y]=2;
                q.push({cnt+1,{x-1,y}});
            }
            if(isValid(x,y+1,m,n) && grid[x][y+1]==1){
                grid[x][y+1]=2;
                q.push({cnt+1,{x,y+1}});
            }
            if(isValid(x,y-1,m,n) && grid[x][y-1]==1){
                grid[x][y-1]=2;
                q.push({cnt+1,{x,y-1}});
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return days;
    }
};
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int time=0;
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            if(x==-1){
                if(!q.empty()){
                    time++;
                    q.push({-1,-1});
                }
            } else {
                if(isValid(x+1,y,m,n) && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                }
                if(isValid(x-1,y,m,n) && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                if(isValid(x,y+1,m,n) && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
                if(isValid(x,y-1,m,n) && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return time;

    }
};
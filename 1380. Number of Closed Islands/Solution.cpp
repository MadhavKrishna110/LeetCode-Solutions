class Solution {
public:
    bool dfs(int i,int j, vector<vector<int>> &visited,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if((i==grid.size()-1 || i==0 || j==grid[0].size()-1 || j==0) && grid[i][j]==0){
            return false;
        }
        visited[i][j]=1;
        bool ans = true;
        if(i+1<m && !visited[i+1][j] && grid[i+1][j]==0){
            ans&=dfs(i+1,j,visited,grid);
        }
        if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]==0){
            ans&=dfs(i-1,j,visited,grid);
        }
        if(j+1<n && !visited[i][j+1] && grid[i][j+1]==0){
            ans&=dfs(i,j+1,visited,grid);
        }
        if(j-1>=0 && !visited[i][j-1] && grid[i][j-1]==0){
            ans&=dfs(i,j-1,visited,grid);
        }
        return ans;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    if(dfs(i,j,visited,grid)){
                        cnt++;
                    }
                    
                }
            }
        }
        return cnt;
    }
};
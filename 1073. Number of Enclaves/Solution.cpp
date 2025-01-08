class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n){
            return false;
        }
        return true;
    }
    void dfs(int i,int j, vector<vector<int>> &visited,vector<vector<int>> &grid){
         int m = grid.size();
        int n = grid[0].size();

        visited[i][j]=1;
        if(isValid(i+1,j,m,n) && !visited[i+1][j] && grid[i+1][j]==1){
            dfs(i+1,j,visited,grid);
        }
        if(isValid(i-1,j,m,n) && !visited[i-1][j] && grid[i-1][j]==1){
            dfs(i-1,j,visited,grid);
        }
        if(isValid(i,j+1,m,n) && !visited[i][j+1] && grid[i][j+1]==1){
            dfs(i,j+1,visited,grid);
        }
        if(isValid(i,j-1,m,n) && !visited[i][j-1] && grid[i][j-1]==1){
            dfs(i,j-1,visited,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,visited,grid);
            }
            if(grid[i][n-1]==1){
                dfs(i,n-1,visited,grid);
            }
        }

         for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(0,i,visited,grid);
            }
            if(grid[m-1][i]==1){
                dfs(m-1,i,visited,grid);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};
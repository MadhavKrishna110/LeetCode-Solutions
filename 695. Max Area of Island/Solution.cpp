class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& visited,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j] || grid[i][j]==0){
            return 0;
        }
        visited[i][j]=1;
        int cnt=1;
        cnt+=dfs(i+1,j,visited,grid);
        cnt+=dfs(i-1,j,visited,grid);
        cnt+=dfs(i,j+1,visited,grid);
        cnt+=dfs(i,j-1,visited,grid);

        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    islands = max(islands,dfs(i,j,visited,grid));
                }
            }
        }
        return islands;
    }
};
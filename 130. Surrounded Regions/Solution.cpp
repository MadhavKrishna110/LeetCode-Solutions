class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n){
            return false;
        }
        return true;
    }
    void dfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        visited[i][j]=1;
        if(isValid(i+1,j,m,n) && !visited[i+1][j] && board[i+1][j]=='O'){
            dfs(i+1,j,visited,board);
        }
        if(isValid(i-1,j,m,n) && !visited[i-1][j] && board[i-1][j]=='O'){
            dfs(i-1,j,visited,board);
        }
        if(isValid(i,j+1,m,n) && !visited[i][j+1] && board[i][j+1]=='O'){
            dfs(i,j+1,visited,board);
        }
        if(isValid(i,j-1,m,n) && !visited[i][j-1] && board[i][j-1]=='O'){
            dfs(i,j-1,visited,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(i,0,visited,board);
            }
            if(board[i][n-1]=='O'){
                dfs(i,n-1,visited,board);
            }
        }
         for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(0,i,visited,board);
            }
            if(board[m-1][i]=='O'){
                dfs(m-1,i,visited,board);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==1){
                    board[i][j]='O';
                } else {
                    board[i][j]='X';
                }
            }
        }
    }
};
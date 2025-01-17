class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& visited){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j] || board[i][j]=='X'){
            return;
        }
        visited[i][j]=1;
        dfs(i-1,j,board,visited);
        dfs(i+1,j,board,visited);
        dfs(i,j+1,board,visited);
        dfs(i,j-1,board,visited);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                cout<<i<<"-"<<0<<endl;
                dfs(i,0,board,visited);
            }
            if(board[i][n-1]=='O'){
                cout<<i<<"-"<<n-1<<endl;
                dfs(i,n-1,board,visited);
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                cout<<0<<"-"<<j<<endl;
                dfs(0,j,board,visited);
            }
            if(board[m-1][j]=='O'){
                cout<<m-1<<"-"<<j<<endl;
                dfs(m-1,j,board,visited);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return ;
    }
};
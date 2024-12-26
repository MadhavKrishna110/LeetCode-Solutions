class Solution {
public:
    bool fun(int i,int j,int idx,string word,vector<vector<char>>& board,vector<vector<int>>& visited){
        int m = board.size();
        int n = board[0].size();
        if(idx==word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;

        if(board[i][j]==word[idx] && !visited[i][j]){
          
            visited[i][j]=1;
            bool a = fun(i+1,j,idx+1,word,board,visited);
            bool b = fun(i-1,j,idx+1,word,board,visited);
            bool c = fun(i,j+1,idx+1,word,board,visited);
            bool d = fun(i,j-1,idx+1,word,board,visited);
            visited[i][j]=0;
            return a||b||c||d;

        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>> visited(m,vector<int>(n,0));
                bool ans = fun(i,j,0,word,board,visited);
                if(ans) return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int m=board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>> visited(m,vector<int> (n,0));
                bool res = backtrack(i,j,0,word,visited,board);
                if(res) return true;
            }
        }
        return false;
    }

    bool backtrack(int i,int j, int k, string word,vector<vector<int>>& visited,vector<vector<char>>& board ){
        if(k==word.length()) return true;
        int m=board.size();
        int n= board[0].size();
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        if(!visited[i][j] && board[i][j]==word[k]){
            visited[i][j]=1;
            bool res = backtrack(i+1,j,k+1,word,visited,board) || backtrack(i-1,j,k+1,word,visited,board) || backtrack(i,j+1,k+1,word,visited,board) || backtrack(i,j-1,k+1,word,visited,board);
            if(res) return true;
            visited[i][j] = 0;
        }
        return false;
    }
};
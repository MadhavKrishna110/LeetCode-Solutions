class Solution {
    bool isSafe(int row,int col,vector<string> board,int n){

        int dupRow = row;
        int dupCol = col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=dupRow;
        col=dupCol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        col= dupCol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
public:
    void fun(int col,int n,vector<string> &board,vector<vector<string>> &result){
        if(col==n){
            result.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                fun(col+1,n,board,result);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        fun(0,n,board,result);
        return result;
    }
};
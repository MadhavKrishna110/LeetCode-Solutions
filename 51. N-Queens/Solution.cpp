class Solution {
public:
    bool isQueenSafe(int row,int col,vector<string> &board){
       // cout<<row<<"-"<<col<<endl;
        int x=row,y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q') return false;
            x--;
            y--;
        }
        x=row;
        y=col;
        while(y>=0){
            if(board[x][y]=='Q') return false;
            y--;
        }

        x=row,y=col;
        while(x<board.size() && y>=0){
            if(board[x][y]=='Q') return false;
            x++;
            y--;
        }
        return true;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &res,int n){
        if(col==n){
            res.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isQueenSafe(row,col,board)){
                cout<<row<<"-"<<col<<endl;
                board[row][col] = 'Q';
                solve(col+1,board,res,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,res,n);
        return res;



    }
};
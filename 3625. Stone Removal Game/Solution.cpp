class Solution {
public:
    bool canAliceWin(int n) {
        int x=10,turn = 0;
        while(n>=x){
            n = n-x;
            x--;
            turn=!turn;
        }
        return turn==0?false:true;
    }
};
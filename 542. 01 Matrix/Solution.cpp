class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> res(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            res[x][y] = dist;
            if(isValid(x+1,y,m,n) && mat[x+1][y]==1 && !visited[x+1][y]){
                visited[x+1][y]=1;
                q.push({{x+1,y},dist+1});
            }
            if(isValid(x-1,y,m,n) && mat[x-1][y]==1 && !visited[x-1][y]){
                visited[x-1][y]=1;
                q.push({{x-1,y},dist+1});
            }
            if(isValid(x,y+1,m,n) && mat[x][y+1]==1 && !visited[x][y+1]){
                visited[x][y+1]=1;
                q.push({{x,y+1},dist+1});
            }
            if(isValid(x,y-1,m,n) && mat[x][y-1]==1 && !visited[x][y-1]){
                visited[x][y-1]=1;
                q.push({{x,y-1},dist+1});
            }

        }
        return res;
    }
};
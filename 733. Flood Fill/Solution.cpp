class Solution {
public:
    bool isValid(int i,int j, int m,int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int m = image.size();
       int n = image[0].size();

       queue<pair<int,int>> q;
       q.push({sr,sc});
        vector<vector<int>> visited(m,vector<int>(n,0));
        visited[sr][sc]=1;
        int tempcol=image[sr][sc];
       while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(isValid(x+1,y,m,n) && !visited[x+1][y] && image[x+1][y]==tempcol){
                q.push({x+1,y});
                visited[x+1][y]=1;
            }
            if(isValid(x-1,y,m,n) && !visited[x-1][y] && image[x-1][y]==tempcol){
                q.push({x-1,y});
                visited[x-1][y]=1;
            }
            if(isValid(x,y+1,m,n) && !visited[x][y+1] && image[x][y+1]==tempcol){
                q.push({x,y+1});
                visited[x][y+1]=1;
            }
            if(isValid(x,y-1,m,n) && !visited[x][y-1] && image[x][y-1]==tempcol){
                q.push({x,y-1});
                visited[x][y-1]=1;
            }
            image[x][y] = color;
       } 
       return image;
    }
};
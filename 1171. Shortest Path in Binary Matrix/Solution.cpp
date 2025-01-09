class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1) return -1;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=1;
        pq.push({1,{0,0}});

        while(!pq.empty()){
            int x= pq.top().second.first;
            int y = pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();
            if(x==m-1 && y==n-1){
                return dis;
            }
            vector<int> directionX = {-1,0,1};
            vector<int> directionY = {-1,0,1};
            for(int i=0;i<directionX.size();i++){
                for(int j=0;j<directionY.size();j++){
                    int newR = x+directionX[i];
                    int newC = y+directionY[j];
                    if(newR>=0 && newR<m && newC>=0 
                    && newC<n && grid[newR][newC]==0 && dist[newR][newC]==1e9){
                        dist[newR][newC]=dis+1;
                        pq.push({dis+1,{newR,newC}});
                    }
                }
            }

        }
        return -1;
    }
};
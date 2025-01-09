class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i<0||j<0 || i>=m|| j>=n){
            return false;
        }
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        while(!pq.empty()){
            int distance = pq.top().first;
            int x= pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x==m-1 && y==n-1){
                return distance;
            }

            if(isValid(x+1,y,m,n) && max(abs(heights[x+1][y]-heights[x][y]),distance)<dist[x+1][y]){
                dist[x+1][y] = max(abs(heights[x+1][y]-heights[x][y]),distance);
                pq.push({dist[x+1][y],{x+1,y}});
            }
            if(isValid(x-1,y,m,n) && max(abs(heights[x-1][y]-heights[x][y]),distance)<dist[x-1][y]){
                dist[x-1][y] = max(abs(heights[x-1][y]-heights[x][y]),distance);
                pq.push({dist[x-1][y],{x-1,y}});
            }
            if(isValid(x,y+1,m,n) && max(abs(heights[x][y+1]-heights[x][y]),distance)<dist[x][y+1]){
                dist[x][y+1] = max(abs(heights[x][y+1]-heights[x][y]),distance);
                pq.push({dist[x][y+1],{x,y+1}});
            }
            if(isValid(x,y-1,m,n) && max(abs(heights[x][y-1]-heights[x][y]),distance)<dist[x][y-1]){
                dist[x][y-1] = max(abs(heights[x][y-1]-heights[x][y]),distance);
                pq.push({dist[x][y-1],{x,y-1}});
            }

        }
        return 0;
    }
};
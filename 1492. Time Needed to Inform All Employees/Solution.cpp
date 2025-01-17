class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> visited(n,0);
        vector<int> dist(n,INT_MAX);
        dist[headID] = informTime[headID];
        pq.push({informTime[headID],{headID,-1}});
        int time = 0;
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            time = max(time,distance);
            pq.pop();
            for(int i=0;i<adj[node].size();i++){
                if(distance+informTime[adj[node][i]]<dist[adj[node][i]]){
                    dist[adj[node][i]] = distance+informTime[adj[node][i]];
                    pq.push({dist[adj[node][i]],{adj[node][i],node}});
                }
            }
        }
        return time;
    }
};
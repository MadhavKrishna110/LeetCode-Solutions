class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            for(int i=0;i<adj[node].size();i++){
                int wt = adj[node][i].second;
                int adjNode = adj[node][i].first;

                if(distance+wt<dist[adjNode]){
                    dist[adjNode] = distance+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int maxm=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            maxm = max(maxm,dist[i]);
            
        }
        return maxm;
    }
};
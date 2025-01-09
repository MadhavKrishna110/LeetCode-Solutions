class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0]=0;
        long long mod = (long long)(1e9+7);
        while(!pq.empty()){
            long long distance = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            

            for(int i=0;i<adj[node].size();i++){
                long long adjNode = adj[node][i].first;
                long long wt = adj[node][i].second;
                long long res = distance+wt;
                if(res<dist[adjNode]){
                    dist[adjNode] = res;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode],adjNode});
                } else if(res == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
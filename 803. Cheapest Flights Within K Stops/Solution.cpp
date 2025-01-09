class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!pq.empty()){
            int stops = pq.top().first;
            int distance = pq.top().second.first;
            int station = pq.top().second.second;
            pq.pop();
            //cout<<distance<<"-"<<stops<<":"<<station<<"="<<dist[station]<<endl;

            for(int i=0;i<adj[station].size();i++){
                int adjStation = adj[station][i].first;
                int adjWt = adj[station][i].second;
                
                if(stops<=k && distance+adjWt<dist[adjStation]){
                    dist[adjStation] = distance+adjWt;
                     //cout<<dist[adjStation]<<"-"<<stops+1<<":"<<station<<"->"<<adjStation<<endl;
                    pq.push({stops+1,{dist[adjStation],adjStation}});
                }
            }
        }
        return dist[dst]!=1e9?dist[dst]:-1;

    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            indegree[i] = graph[i].size();
            if(indegree[i]==0){
                q.push(i);
            }
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int i=0;i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;

    }
};
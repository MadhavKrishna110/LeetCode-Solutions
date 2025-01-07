// class Solution {
// public:
//     void dfs(int idx,vector<vector<int>> adjList,vector<bool> &visited){
//         visited[idx]=true;
//         for(int i: adjList[idx]){
//             if(!visited[i]){
//                 dfs(i,adjList,visited);
//             }
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if(connections.size()<n-1) return -1;
//         vector<vector<int>> adj(n);
//        for(auto c : connections){
//             adj[c[0]].push_back(c[1]);
//             adj[c[1]].push_back(c[0]);
//         }
//         vector<bool> visited(n,false);
//         int components=0;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 dfs(i,adj,visited);
//                 components++;
//             }
//         }
//         return components-1;
//     }
// };

class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src){
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for(auto c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i]){
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};
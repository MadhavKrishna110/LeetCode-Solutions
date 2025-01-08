class Solution {
public:
    bool dfs(int node,int color,vector<int>& visited,vector<vector<int>>& graph){

        visited[node] = color;
        bool ans=true;
        for(int i:graph[node]){
            if(visited[i]==-1){
                ans = ans && dfs(i,1-color,visited,graph);
            } else if(visited[i]==visited[node]){
                return false;
            }
        }
        return ans;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                bool ans = dfs(i,0,visited,graph);
                if(!ans) return false;
            }
            
        }
        return true;
    }
};
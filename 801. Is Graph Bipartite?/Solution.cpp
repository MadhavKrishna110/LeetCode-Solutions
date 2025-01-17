class Solution {
public:
    bool dfs(int node,int color,vector<int> &pathVisited, vector<int> &visited,vector<vector<int>>& graph){

        pathVisited[node] = color;
        visited[node]=1;
        bool ans = true;
        for(int i:graph[node]){
            if(pathVisited[i]!=-1 && pathVisited[i]==color){
                return false;
            } else if(!visited[i]){
                ans= ans && dfs(i,!color,pathVisited,visited,graph);
            }
        }
        pathVisited[node]=-1;
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> pathVisited(n,-1);

        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                if(!dfs(i,0,pathVisited,visited,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};
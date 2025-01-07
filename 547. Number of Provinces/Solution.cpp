class Solution {
public:
    void dfs(int idx,vector<int> adjList,vector<vector<int>>& isConnected,vector<int> &visited){
        if(idx>=adjList.size()) return;

        visited[idx]=1;
        for(int i=0;i<adjList.size();i++){
            if(i!=idx && adjList[i]==1 && !visited[i]){
                dfs(i,isConnected[i],isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected[i],isConnected,visited);
                provinces++;
            }
        }
        return provinces;
    }
};
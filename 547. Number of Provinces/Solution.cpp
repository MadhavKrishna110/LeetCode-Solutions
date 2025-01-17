class Solution {
public:
    void dfs(int idx,vector<int>& visited,vector<vector<int>> &adjList){
        if(visited[idx]) return;

        visited[idx]=1;
        for(int i:adjList[idx]){
            dfs(i,visited,adjList);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adjList);
                provinces++;
            }

        }
        return provinces;
    }
};
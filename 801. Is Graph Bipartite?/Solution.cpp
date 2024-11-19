class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();

        queue<int> q;
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]!=-1) continue;

            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
            cout<<node<<"-"<<color[node]<<endl;
                for(int j=0;j<graph[node].size();j++){
                    int item = graph[node][j];
                    if(color[item]==-1){
                        color[item] = 1-color[node];
                        q.push(graph[node][j]);
                    } else if(color[item]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
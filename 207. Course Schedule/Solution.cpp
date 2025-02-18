class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // prerequisites[i] = [ai, bi] indicates that you must take course bi first if
        // you want to take course ai => Dependency is on bi => bi ki indegree badhegi.
        // => There is an edge from ai to bi. (v equals n here)

        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vector<int> indegree(n+1,0);
        for(int i=0;i<n;i++){
            for(auto child: adj[i])
                indegree[child]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){
            int curr=q.front();
            for(auto child:adj[curr]){
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
            q.pop();
        }

        for(int i=0;i<n;i++){
            if(indegree[i]!=0)
                return false;
        }
        return true;
    }
};
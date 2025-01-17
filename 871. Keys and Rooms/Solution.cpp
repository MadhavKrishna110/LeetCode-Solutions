class Solution {
public:
    void dfs(int idx,vector<int> &visited,vector<vector<int>>& rooms){
        visited[idx]=1;
        for(int i=0;i<rooms[idx].size();i++){
            if(!visited[rooms[idx][i]]){
                dfs(rooms[idx][i],visited,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        dfs(0,visited,rooms);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
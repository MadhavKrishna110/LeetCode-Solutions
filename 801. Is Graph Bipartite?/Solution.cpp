class Solution {
public:
    bool fun(int ind,int prevColor,vector<int> &color,vector<vector<int>> graph){
        color[ind]=prevColor;

        for(int i=0;i<graph[ind].size();i++){
            if(color[graph[ind][i]]==-1){
               if(fun(graph[ind][i],1-prevColor,color,graph)==false) return false;
            } else {
                if(color[graph[ind][i]]==prevColor){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(fun(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};
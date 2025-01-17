class Solution {
public:
    void dfs(int sr,int sc,int initialColor,int color,vector<vector<int>> &image,vector<vector<int>> &visited){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()||image[sr][sc]!=initialColor || visited[sr][sc]){
            return;
        }

        visited[sr][sc]=1;
        image[sr][sc]=color;
        dfs(sr-1,sc,initialColor,color,image,visited);
        dfs(sr+1,sc,initialColor,color,image,visited);
        dfs(sr,sc-1,initialColor,color,image,visited);
        dfs(sr,sc+1,initialColor,color,image,visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        dfs(sr,sc,image[sr][sc],color,image,visited);
        return image;
    }
};
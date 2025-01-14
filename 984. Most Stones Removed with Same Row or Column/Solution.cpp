class Solution {
     class DisjointSet{
        vector<int> parent,size;
        public:
        DisjointSet(int n){
            parent = vector<int>(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
            size = vector<int>(n+1,1);
        }

        int findUPar(int node){
            if(parent[node]==node){
                return node;
            }
            //cout<<node<<"-"<<parent[node]<<endl;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int x, int y){
            int ulp_x = findUPar(x);
            int ulp_y = findUPar(y);

            if(ulp_x==ulp_y) return;

            if(size[ulp_x]<size[ulp_y]){
                parent[ulp_x] = ulp_y;
                size[ulp_y]+=size[ulp_x];
            } else {
                parent[ulp_y]=parent[ulp_x];
                size[ulp_x] += size[ulp_y];
            }
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
       int row=0,col=0;
       for(int i=0;i<stones.size();i++){
        row = max(row,stones[i][0]);
        col = max(col,stones[i][1]);
       }
       DisjointSet ds(row+col+1);
       unordered_map<int,int> mp;
       for(int i=0;i<stones.size();i++){
        ds.unionBySize(stones[i][0],stones[i][1]+row+1);
        mp[stones[i][0]]=1;
        mp[stones[i][1]+row+1]=1;
       // ds.unionBySize(stones[i][1]+col+1,stones[i][0]);
       }
        int num=0;
       for(auto i:mp){
        if(ds.findUPar(i.first)==i.first){
            num++;
        }
       }

       return stones.size()-num;
    }
};
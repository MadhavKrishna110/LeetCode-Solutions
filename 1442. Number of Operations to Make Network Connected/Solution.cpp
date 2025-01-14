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
            cout<<node<<"-"<<parent[node]<<endl;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //if(connections.size()<n-1) return -1;
        DisjointSet ds(n);
        int cntExtras=0;
        for(int i=0;i<connections.size();i++){
            if(ds.findUPar(connections[i][0])==ds.findUPar(connections[i][1])){
                cntExtras++;
            }
            ds.unionBySize(connections[i][0],connections[i][1]);
            ds.unionBySize(connections[i][1],connections[i][0]);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
                components++;
            }
        }
        return cntExtras>=components-1?components-1:-1;

    }
};
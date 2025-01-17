class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adjMatrix(n+1,vector<int>(n+1,0));

        for(int i=0;i<trust.size();i++){
            adjMatrix[trust[i][0]][trust[i][1]]++;
        }
        vector<int> candidates;
        for(int i=1;i<=n;i++){
            bool ans=true;
            for(int j = 1;j<=n;j++){
               if(adjMatrix[i][j]!=0){
                  ans=false;
               }
            }
            if(ans){
                //cout<<i<<endl;
                bool flag=true;
                for(int j=1;j<=n;j++){
                    if(j!=i && adjMatrix[j][i]==0){
                        flag=false;
                    }
                }
                if(flag) return i;
            }
        }
        return -1;
    }
};
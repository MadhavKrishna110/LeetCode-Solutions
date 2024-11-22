class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> year(2051,0);
        for(int i=0;i<logs.size();i++){
            year[logs[i][0]]++;
            year[logs[i][1]]--;
        }
        int res=0,sum=0,resYear=logs[0][0];
        for(int i=1950;i<=2050;i++){
            sum+=year[i];
            if(sum>res){
                res=sum;
                resYear = i;
            }
        }
        return resYear;
    }
};
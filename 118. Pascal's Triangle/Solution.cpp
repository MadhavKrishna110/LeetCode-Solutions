class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        if(numRows==1) return result;
        result.push_back({1,1});
        if(numRows==2) return result;
        int i=2;
        while(i<numRows){
            int start=0,next=1;
            vector<int> v;
            v.push_back(1);
            while(next<i){
                v.push_back(result[i-1][start]+result[i-1][next]);
                start++;
                next++;
            }
            v.push_back(1);
            result.push_back(v);
            i++;
        }
        return result;
    }
};
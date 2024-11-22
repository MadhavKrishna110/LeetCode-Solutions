class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {

        auto cmp= [](const vector<int> &a,const vector<int> &b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        };
        sort(points.begin(),points.end(),cmp);
        int arrow=1,prev=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>prev){
                arrow++;
                prev=points[i][1];
            }
        }
        return arrow;
    }
};
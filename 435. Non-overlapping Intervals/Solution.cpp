class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int> &a,vector<int> &b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        int prev=intervals[0][1],rooms=0;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev){
                rooms++;
            } else {
                prev = intervals[i][1];
            }
        }
        return rooms;
    }
};
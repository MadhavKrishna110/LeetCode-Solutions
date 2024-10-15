class Solution {
public:
    struct Comparator {
    bool operator()(vector<int> a, vector<int> b) const
    {
        // Custom comparison logic
        return a[0] < b[0]; // this sorts in ascending order
    }
};
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
       sort(intervals.begin(),intervals.end(),Comparator()); 
        int curr=0;
       while(curr<intervals.size()){
            int start=intervals[curr][0],end= intervals[curr][1];
            curr++;
            while(curr<intervals.size() && intervals[curr][0]<=end){
                end = max(end,intervals[curr][1]);
                curr++;
            }
            v.push_back({start,end});
       }

       return v;
    }
};
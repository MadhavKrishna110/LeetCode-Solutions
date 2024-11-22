class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> arr(102,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i][0]]++;
            arr[nums[i][1]+1]--;
        }
        int sum=0,res=0;
        for(int i=1;i<=100;i++){
            sum+=arr[i];
            if(sum>0 ){
                res++;
            }
        }
        return res;
    }
};
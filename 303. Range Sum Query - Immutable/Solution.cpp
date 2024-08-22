class NumArray {
    vector<int> arr;
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]);
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return prefixSum[right];
        } else {
            return prefixSum[right]- prefixSum[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
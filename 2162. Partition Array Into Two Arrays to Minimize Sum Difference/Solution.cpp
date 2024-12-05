class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
        }

        int n = N/2;
        vector<vector<int>> left(n+1),right(n+1);

        for(int mask=0;mask<(1<<n);++mask){
            int idx=0,l=0,r=0;
            for(int i=0;i<=n;i++){
                if(mask&(1<<i)){
                    idx++;
                    l+=nums[i];
                    r+=nums[i+n];
                }
            }
            left[idx].push_back(l);
            right[idx].push_back(r);
        }

        for(int i=0;i<=n;i++){
            sort(right[i].begin(),right[i].end());
        }

        int res = min(abs(sum-2*left[n][0]),abs(sum-2*right[n][0]));
        for(int idx=1;idx<=n;idx++){
            for(auto &a:left[idx]){
                int b = (sum-2*a)/2;
                int rightIdx = n-idx;
                auto &v = right[rightIdx];
                auto itr = lower_bound(v.begin(),v.end(),b);

                if(itr!=v.end()){
                    res = min(res,abs(sum-2*(a+(*itr))));
                }
            }
        }

        return res;
    }
};